cmake_minimum_required(VERSION 3.10)

project("triangles" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_FLAGS "-std=c++20")




add_library(win STATIC ./source/classes/win/win.cpp)
add_library(cfg STATIC ./source/classes/cfg/cfg.cpp)
add_library(tri STATIC ./source/classes/tri/tri.cpp)


add_executable(triangles source/main.cpp)
set(SFML_DIR SFML-2.5.1/lib/cmake/SFML)
target_include_directories(triangles PUBLIC include)

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED )
target_link_libraries(win cfg sfml-audio sfml-graphics sfml-window sfml-system)
target_link_libraries(tri sfml-audio sfml-graphics sfml-window sfml-system)
target_link_libraries(triangles win tri)