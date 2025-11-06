cmake_minimum_required(VERSION 3.20)
project(Project-Z LANGUAGES CXX)

# Enable C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# --- Fetch SFML 3.0.0 ---
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
)

FetchContent_MakeAvailable(SFML)

# --- Add your source files ---
add_executable(game src/main.cpp src/window.cpp src/player.cpp) 
# --- Link SFML ---
target_link_libraries(game PRIVATE SFML::Graphics SFML::Window SFML::System)