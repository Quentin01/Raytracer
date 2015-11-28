cmake_minimum_required(VERSION 2.6)
project(RAYTRACER)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

set(EXECUTABLE_NAME "rt")
add_executable(${EXECUTABLE_NAME} ${SRC_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++11")
endif()
