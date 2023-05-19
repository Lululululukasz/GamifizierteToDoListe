cmake_minimum_required(VERSION 3.22)
project(pic_aem_projekt)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
add_executable(pic_aem_projekt main.cpp Task.cpp Categories.cpp GUI/TaskWidget.h GUI/TaskWidget.cpp)
target_link_libraries(pic_aem_projekt Qt5::Widgets)
