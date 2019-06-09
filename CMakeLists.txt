cmake_minimum_required(VERSION 3.14.4)

project(mergeOV2)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core CONFIG REQUIRED)

set(MY_HDR
	src/EntryBase.h
	src/EntryDelete.h
	src/EntrySkipp.h
	src/EntrySimple.h
	src/EntryExtended.h
)

set(MY_SRC
	src/main.cpp
)

add_executable(${PROJECT_NAME} ${MY_SRC} ${MY_HDR})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
