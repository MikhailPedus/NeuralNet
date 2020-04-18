cmake_minimum_required(VERSION 2.6)

if (CMAKE_VERSION VERSION_LESS "3.1")
	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
	endif ()
else ()
	set (CMAKE_CXX_STANDARD 11)
endif ()

project(hello)

find_package(Threads)
find_package(OpenCV REQUIRED)
find_package(GTest REQUIRED)

add_executable(hello src/main.cpp)
target_link_libraries(hello ${OpenCV_LIBS})
