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

add_library(core 
	src/core/layer.cpp 
	src/core/tensor.cpp 
	src/core/activation_func.cpp
	src/core/layers/AddLayer.cpp)

target_include_directories(core
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    )

add_executable(hello src/main.cpp)

target_include_directories(hello
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    )
target_link_libraries(hello core ${OpenCV_LIBS})

#tests
add_subdirectory(tests)
