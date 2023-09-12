#include <SFML/Graphics.hpp>

#include <iostream>
#include <random>

// Constants
const unsigned int WINDOW_SIZE = 600U;
const unsigned long TOTAL_ITERATIONS = 1'000'000UL;

// Random number generator class
class Random {
public:
    static Random &GetInstance() {
        static Random instance;
        return instance;
    }

    // Generate a random float in the specified range
    float Float(float a, float b) {
        auto distribution = std::uniform_real_distribution<float>(a, b);
        auto engine = std::mt19937(mRandomDevice());
        return distribution(engine);
    }

private:
    std::random_device mRandomDevice;
};

int main() {
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Pi Approximation", sf::Style::Close, sf::ContextSettings(0U, 0U, 8U));
    window.setFramerateLimit(60U);

    // Set the window icon if available
    if (sf::Image favicon; favicon.loadFromFile("assets/favicon.png")) {
        window.setIcon(favicon.getSize().x, favicon.getSize().y, favicon.getPixelsPtr());
    }

    // Initialize counts for points inside the circle and total points
    unsigned long pointsInsideCircleCount = 0UL;
    unsigned long totalPointsCount = 0UL;

    // Create a vertex array for efficient point rendering
    sf::VertexArray points(sf::Points);

    // Main loop
    while (window.isOpen() && totalPointsCount < TOTAL_ITERATIONS) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Handle window close event
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Generate and render points
        for (unsigned long iteration = 0UL; iteration < 1'000UL && totalPointsCount < TOTAL_ITERATIONS; iteration++) {
            // Generate random coordinates
            float x = Random::GetInstance().Float(0.0f, 1.0f);
            float y = Random::GetInstance().Float(0.0f, 1.0f);

            // Create a vertex for the point
            sf::Vertex vertex;
            vertex.position = {x * WINDOW_SIZE, y * WINDOW_SIZE};

            // Calculate the squared distance from the origin
            float distanceSquared = x * x + y * y;

            // Check if the point is inside the unit circle and set its color
            if (distanceSquared <= 1.0f) {
                vertex.color = sf::Color::Red;
                pointsInsideCircleCount++;
            } else {
                vertex.color = sf::Color::Blue;
            }

            // Add the vertex to the vertex array
            points.append(vertex);
            totalPointsCount++;
        }

        // Clear the window and draw the points
        window.clear(sf::Color::White);
        window.draw(points);
        window.display();
    }

    // Calculate the approximation of pi
    float pi = 4.0f * static_cast<float>(pointsInsideCircleCount) / static_cast<float>(totalPointsCount);

    // Print the result
    std::printf("%.15f\n", pi);

    return 0;
}