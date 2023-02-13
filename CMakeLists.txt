cmake_minimum_required(VERSION 3.24)
project(Pong)

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/libs/SFML/include)
include_directories(${SFML_INCLUDE})
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/SFML)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
add_executable(Pong main.cpp src/application/Application.cpp src/application/Application.hpp src/components/IComponent.hpp src/components/RenderComponent.cpp src/components/RenderComponent.hpp src/window/Window.cpp src/window/Window.hpp src/gameobject/GameObject.cpp src/gameobject/GameObject.hpp src/components/RectangleComponent.cpp src/components/RectangleComponent.hpp src/gameobject/Scene.cpp src/gameobject/Scene.hpp src/gameobject/Player.cpp src/gameobject/Player.hpp src/gameobject/Ball.cpp src/gameobject/Ball.hpp src/gameobject/Enemy.cpp src/gameobject/Enemy.hpp src/gameobject/Paddle.cpp src/gameobject/Paddle.hpp src/gameobject/Border.cpp src/gameobject/Border.hpp src/components/TextComponent.cpp src/components/TextComponent.hpp src/gameobject/Score.cpp src/gameobject/Score.hpp src/gameobject/ScoreObserver.cpp src/gameobject/ScoreObserver.hpp src/components/SoundComponent.cpp src/components/SoundComponent.hpp)
target_link_libraries(Pong  sfml-graphics sfml-audio)
