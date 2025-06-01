cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
    #set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /WX")
else()
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

add_subdirectory("projects/matrix")
add_subdirectory("projects/unit_tests")
add_subdirectory("projects/benchmarks")