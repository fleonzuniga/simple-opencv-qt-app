cmake_minimum_required(VERSION 3.16.3)
set(PROJECT "TEST")
project(${PROJECT} VERSION "1.0.0")

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

configure_file(${CMAKE_SOURCE_DIR}/cmake/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)
add_executable(${PROJECT_NAME} main.cpp
                               GUI/mainwindow.cpp
                               GUI/mainwindow.h
                               GUI/mainwindow.ui
                               VideoCapture/videoCapture.cpp
                               VideoCapture/videoCapture.h
                               Process/process.cpp
                               Process/process.h)

target_link_libraries(${PROJECT_NAME}
                      ${OpenCV_LIBS}
                      Qt5::Widgets)
