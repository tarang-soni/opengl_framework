cmake_minimum_required(VERSION 3.20)

project(SnakeGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# ------------------------
# GLFW
# ------------------------
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)

FetchContent_MakeAvailable(glfw)

# ------------------------
# Executable
# ------------------------
add_executable(SnakeGame
        src/main.cpp
        src/Game.cpp
        src/GameObject.cpp
        src/GameState.cpp
        src/GameStateManager.cpp
        src/Fruit.cpp
        src/MenuState.cpp
        src/Quad.cpp
        src/Shader.cpp
        src/Snake.cpp
        src/SnakeBody.cpp
        src/glad.c
)

# ------------------------
# Include directories
# ------------------------
target_include_directories(SnakeGame PRIVATE
        include
        external/glad/include
        external/glm
)

# ------------------------
# Link libraries
# ------------------------
target_link_libraries(SnakeGame PRIVATE
        glfw
        opengl32
)

# ------------------------
# MSVC warnings
# ------------------------
if(MSVC)
    target_compile_options(SnakeGame PRIVATE /W4)
else()
    target_compile_options(SnakeGame PRIVATE -Wall -Wextra -pedantic)
endif()