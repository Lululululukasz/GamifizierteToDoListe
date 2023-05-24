cmake_minimum_required(VERSION 3.22)
project(pic_aem_projekt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMake_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
add_subdirectory(todolib)
add_executable(pic_aem_projekt main.cpp GUI/TaskWidget.cpp GUI/TaskWidget.h GUI/ToDoListWindow.cpp GUI/ToDoListWindow.h GUI/CategoryWidget.h GUI/CategoryWidget.cpp AddTaskBox.cpp AddTaskBox.h Window.cpp Window.h)
target_link_libraries(pic_aem_projekt Qt5::Widgets)
target_link_libraries(pic_aem_projekt todolib)