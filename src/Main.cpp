#include <SFML/Graphics.hpp>

#include "imgui-SFML.h"
#include "imgui.h"

#include <random>

const unsigned int WINDOW_SIZE = 600U;
const unsigned long TOTAL_ITERATIONS = 1'000'000UL;

int main() {
    std::random_device mRandomDevice;
    auto distribution = std::uniform_real_distribution<float>(0.0f, 1.0f);
    auto engine = std::mt19937(mRandomDevice());

    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Pi Approximation", sf::Style::Close, sf::ContextSettings(0U, 0U, 8U));
    window.setFramerateLimit(60U);

    (void) ImGui::SFML::Init(window);

    unsigned long pointsInsideCircleCount = 0UL;
    unsigned long totalPointsCount = 0UL;

    sf::VertexArray points(sf::Points);

    sf::Clock deltaClock;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        for (unsigned long iteration = 0UL; iteration < 1'000UL; iteration++) {
            if (totalPointsCount >= TOTAL_ITERATIONS) break;

            float x = distribution(engine);
            float y = distribution(engine);

            sf::Vertex vertex;
            vertex.position = {x * WINDOW_SIZE, y * WINDOW_SIZE};

            if (float distanceSquared = x * x + y * y; distanceSquared <= 1.0f) {
                vertex.color = sf::Color::Red;
                pointsInsideCircleCount++;
            } else {
                vertex.color = sf::Color::Blue;
            }

            points.append(vertex);
            totalPointsCount++;
        }

        window.clear(sf::Color::White);
        window.draw(points);

        float pi = 4.0f * static_cast<float>(pointsInsideCircleCount) / static_cast<float>(totalPointsCount);

        ImGui::Begin("Result");
        ImGui::Text("%.15f", pi);
        ImGui::End();

        ImGui::SFML::Render(window);

        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
