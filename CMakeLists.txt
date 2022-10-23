cmake_minimum_required(VERSION 2.8)
project(quat2rm)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

include_directories("/usr/include/eigen3")
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(quat2rm main.cpp)
target_link_libraries(quat2rm ${OpenCV_LIBS})