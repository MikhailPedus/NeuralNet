#tests for stereogram builder/solver
find_package(GTest REQUIRED)

add_executable(layers_tests LayersTests.cpp AddLayerTests.cpp FullyConnectedTests.cpp)

target_link_libraries(layers_tests debug core ${GTEST_LIBRARY_DEBUG} ${GTEST_MAIN_LIBRARY_DEBUG})
target_link_libraries(layers_tests optimized core ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})

include_directories(layers_tests ${GTEST_INCLUDE_DIR} ${CORE_INCLUDE_DIRS})
