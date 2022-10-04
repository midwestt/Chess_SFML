cmake_minimum_required(VERSION 3.0.0)
project(Chess)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(SFML 2.5.1 REQUIRED COMPONENTS graphics window system)

include_directories(${SFML_INCLUDE_DIR})
add_executable(Chess 
	src/main.cpp
	src/Board.cpp
	src/Board.h
	src/ChessPieces.cpp
	src/ChessPieces.h
	src/MainWindow.cpp
	src/MainWindow.h
	src/SettingsProvider.cpp
	src/SettingsProvider
)

target_link_libraries(Chess ${SFML_LIBRARIES})