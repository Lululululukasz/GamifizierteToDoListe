cmake_minimum_required(VERSION 3.22)
project(pic_aem_projekt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMake_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets Multimedia REQUIRED)
add_subdirectory(todolib)
add_executable(pic_aem_projekt
		main.cpp
		GUI/TaskWidget.cpp GUI/TaskWidget.h
		GUI/CategoryViewPage.cpp GUI/CategoryViewPage.h
		GUI/CategoryWidget.h GUI/CategoryWidget.cpp
		GUI/AddTaskBox.cpp GUI/AddTaskBox.h
		GUI/MainWindow.cpp GUI/MainWindow.h
		GUI/Page.cpp GUI/Page.h
		GUI/MainPage.cpp GUI/MainPage.h
		GUI/Points.h GUI/Points.cpp
		utility/Globals.cpp utility/JsonList.tpp)
target_link_libraries(pic_aem_projekt Qt5::Widgets Qt5::Multimedia)
target_link_libraries(pic_aem_projekt todolib)

# create install target
install(TARGETS pic_aem_projekt DESTINATION bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/resources/
		DESTINATION resources)

if (WIN32)
	# add all mingw64 system dlls to install target
	# this is overkill, but collecting only the needed dlls is a pain
	set(MINGW_ROOT "c:/msys64/mingw64")
	# install all dlls except those which start with Qt5
	install(DIRECTORY ${MINGW_ROOT}/bin/ DESTINATION bin
		FILES_MATCHING
		PATTERN "*.dll"
		PATTERN "Qt5*" EXCLUDE)

	# add all qt dlls to install target
	include(cmake/WinDeployQt.cmake)
	windeployqt(pic_aem_projekt "bin")
endif (WIN32)

# make deployment using cpack and nsis
set(CPACK_GENERATOR "NSIS")
set(CPACK_PACKAGE_NAME "pic_aem_projekt")
set(CPACK_PACKAGE_VENDOR "gruppe6")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "pic_aem_projekt")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "pic_aem_projekt")
set(CPACK_NSIS_MODIFY_PATH OFF)
set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL OFF)
set(CPACK_NSIS_IGNORE_LICENSE_PAGE ON)
set(CPACK_NSIS_EXECUTABLES_DIRECTORY ".")
#set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")
#set(CPACK_NSIS_MUI_UNIICON "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")
set(CPACK_NSIS_MENU_LINKS
        "bin/pic_aem_projekt.exe" "pic_aem_projekt"
        )

include(CPack)
