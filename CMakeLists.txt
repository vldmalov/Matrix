cmake_minimum_required(VERSION 3.24)
project(Matrix)
set(target_name "Matrix")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4 /WX")
else()
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

file(GLOB_RECURSE source_files "./matrix/source/*.cpp")
file(GLOB_RECURSE include_files "./matrix/include/*.h")
set(all_sources ${source_files} ${include_files})
add_executable(${target_name} WIN32 MACOSX_BUNDLE ${all_sources})

target_include_directories(${target_name} PRIVATE "./matrix/include")
