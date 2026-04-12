# 1. Toolchain musi być pierwszy
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE PATH "")
set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "")

cmake_minimum_required(VERSION 3.16)
project(RedaktorAI VERSION 1.0 LANGUAGES CXX)

# --- 2. WYMUSZENIE ŚCIEŻEK DLA CPR I JSON (Skoro automat zawodzi) ---
set(VCPKG_INSTALLED_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-windows")
list(APPEND CMAKE_PREFIX_PATH "${VCPKG_INSTALLED_PATH}/share/cpr")
list(APPEND CMAKE_PREFIX_PATH "${VCPKG_INSTALLED_PATH}/share/nlohmann_json")

# --- 3. KONFIGURACJA QT ---
set(QT_PATH "C:/Users/Julia/Desktop/qt/6.11.0/msvc2022_64")
list(APPEND CMAKE_PREFIX_PATH "${QT_PATH}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# --- 4. SZUKANIE PAKIETÓW ---
# Szukamy Qt (dodajemy NO_DEFAULT_PATH dla bezpieczeństwa)
find_package(Qt6 REQUIRED COMPONENTS Widgets Concurrent PATHS ${QT_PATH} NO_DEFAULT_PATH)

# Szukamy CPR i JSON - wskazujemy foldery bezpośrednio, jeśli vcpkg-toolchain zawiedzie
find_package(cpr REQUIRED PATHS "${VCPKG_INSTALLED_PATH}/share/cpr")
find_package(nlohmann_json REQUIRED PATHS "${VCPKG_INSTALLED_PATH}/share/nlohmann_json")

# --- 5. RESZTA PROJEKTU ---
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/mainwindow.ui
    src/OllamaClient.cpp
    src/OllamaClient.h
)

add_executable(RedaktorAI WIN32 ${SOURCES})

target_link_libraries(RedaktorAI PRIVATE 
    Qt6::Widgets 
    Qt6::Concurrent
    cpr::cpr 
    nlohmann_json::nlohmann_json
)