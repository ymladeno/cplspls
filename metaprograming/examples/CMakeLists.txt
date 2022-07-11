cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)

# add_executable( meta1
# 				src/main.cpp)

# add_executable( cpyt
# 				src/copy.cpp)

add_executable( sel
				src/select.cpp)

add_executable( con
				src/conditional.cpp)

add_executable( fac
				src/factorial.cpp)

add_executable( eif
				src/enable_if.cpp)

add_executable( seif
				src/std_enable_if.cpp)