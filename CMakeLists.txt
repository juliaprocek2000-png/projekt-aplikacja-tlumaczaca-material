cmake_minimum_required(VERSION 3.10)

# USTAWIENIE ŚCIEŻKI DO VCPKG (Zrobimy to przed project!)
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(TlumaczPojec)

set(CMAKE_CXX_STANDARD 17)

# Szukanie paczek
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Pliki źródłowe - upewnij się, że masz takie foldery i pliki!
add_executable(TlumaczPojec 
    src/main.cpp 
    src/OllamaClient.cpp
)

# Dodanie folderu z plikami .h
target_include_directories(TlumaczPojec PRIVATE include)

# Linkowanie bibliotek
target_link_libraries(TlumaczPojec PRIVATE cpr::cpr nlohmann_json::nlohmann_json)