cmake_minimum_required(VERSION 3.14.4)

project(mergeOV2)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Concurrent CONFIG REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fuse-ld=gold")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")

set(MY_HDR
	src/EntryBase.h
	src/EntryDelete.h
	src/EntrySkipp.h
	src/EntrySimple.h
	src/EntryExtended.h
	src/config.h
	src/Controller.h
	src/ReadOV2.h
)

set(MY_SRC
	src/main.cpp
	src/Controller.cpp
	src/ReadOV2.cpp
)

add_executable(${PROJECT_NAME} ${MY_SRC} ${MY_HDR})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Concurrent)
