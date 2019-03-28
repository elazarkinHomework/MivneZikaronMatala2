cmake_minimum_required (VERSION 2.6)

project (Homework2)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")

SET(
	TREE_LIB_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/Tree.cpp
)


SET(
	TESTER_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/TreeTester.cpp 
)

add_library(TreeLib STATIC ${TREE_LIB_SOURCES})

add_executable(TreeTester ${TESTER_SOURCES})

target_link_libraries(TreeTester pthread TreeLib)
