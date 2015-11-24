cmake_minimum_required(VERSION 2.6)
project(RAYTRACER)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

set(EXECUTABLE_NAME "rt")
add_executable(${EXECUTABLE_NAME} ${SRC_FILES})

find_package(SFML 2 REQUIRED system window graphics)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

