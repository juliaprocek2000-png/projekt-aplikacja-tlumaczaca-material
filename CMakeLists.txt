set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE PATH "")
set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "")

cmake_minimum_required(VERSION 3.16)
project(RedaktorAI VERSION 1.0 LANGUAGES CXX)

set(VCPKG_INSTALLED_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-windows")
list(APPEND CMAKE_PREFIX_PATH "${VCPKG_INSTALLED_PATH}/share/cpr")
list(APPEND CMAKE_PREFIX_PATH "${VCPKG_INSTALLED_PATH}/share/nlohmann_json")

set(QT_PATH "C:/Users/Julia/Desktop/qt/6.11.0/msvc2022_64")
list(APPEND CMAKE_PREFIX_PATH "${QT_PATH}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Concurrent PATHS ${QT_PATH} NO_DEFAULT_PATH)
find_package(cpr REQUIRED PATHS "${VCPKG_INSTALLED_PATH}/share/cpr")
find_package(nlohmann_json REQUIRED PATHS "${VCPKG_INSTALLED_PATH}/share/nlohmann_json")

set(SOURCES
    src/main.cpp
    src/gui/mainwindow.cpp
    src/gui/mainwindow.h
    src/gui/mainwindow.ui
    src/network/OllamaClient.cpp
    src/network/OllamaClient.h
)

add_executable(RedaktorAI WIN32 ${SOURCES})

target_include_directories(RedaktorAI PRIVATE 
    src/gui 
    src/network
)

target_link_libraries(RedaktorAI PRIVATE 
    Qt6::Widgets 
    Qt6::Concurrent
    cpr::cpr 
    nlohmann_json::nlohmann_json
)

enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Test)


add_executable(UnitTests 
    tests/test_ollama.cpp 
    src/network/OllamaClient.cpp 
)
target_include_directories(UnitTests PRIVATE 
    src/network
)

target_link_libraries(UnitTests 
    Qt6::Test 
    cpr::cpr 
    nlohmann_json::nlohmann_json
)

add_test(NAME OllamaConnectionTest COMMAND UnitTests)