cmake_minimum_required (VERSION 2.6)

project (Homework2)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")

SET(
	SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/Tree.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/TreeDemo.cpp 
)

add_executable(TreeDemo ${SOURCES})

target_link_libraries(TreeDemo pthread)
