#tests for stereogram builder/solver
find_package(GTest REQUIRED)

add_executable(layers_tests AddLayerTests.cpp)
target_link_libraries(layers_tests core ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})
include_directories(layers_tests ${GTEST_INCLUDE_DIR})
