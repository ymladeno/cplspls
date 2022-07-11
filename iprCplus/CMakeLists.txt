cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)

add_executable( ipr
                src/impl.cpp
				src/main.cpp
				)

target_include_directories(ipr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)