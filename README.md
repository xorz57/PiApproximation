# PiApproximation

[![Build](https://github.com/xorz57/PiApproximation/actions/workflows/Build.yml/badge.svg)](https://github.com/xorz57/PiApproximation/actions/workflows/Build.yml)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=xorz57_PiApproximation&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=xorz57_PiApproximation)

![image](https://github.com/xorz57/PiApproximation/assets/84932056/0c3ba88e-5474-498c-bb50-13c617f28553)

## Dependencies

- [SFML](https://github.com/SFML/SFML)
- [ImGui-SFML](https://github.com/SFML/imgui-sfml)

## How to Build

#### Linux & macOS

```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
~/vcpkg/bootstrap-vcpkg.sh

git clone https://github.com/xorz57/PiApproximation.git
cd PiApproximation
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```

#### Windows

```powershell
git clone https://github.com/microsoft/vcpkg.git C:/vcpkg
C:/vcpkg/bootstrap-vcpkg.bat
C:/vcpkg/vcpkg.exe integrate install

git clone https://github.com/xorz57/PiApproximation.git
cd PiApproximation
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```
