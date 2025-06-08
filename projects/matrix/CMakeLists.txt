set(target_name "Matrix")
project(Matrix LANGUAGES CXX)
message("Build project: ${target_name}")

file(GLOB_RECURSE source_files "./source/*.cpp")
file(GLOB_RECURSE include_files "./include/*.h")

set(all_sources ${source_files} ${include_files}
        include/MatrixUtils.h
        source/MatrixUtils.cpp)
add_executable(${target_name} MACOSX_BUNDLE ${all_sources})

source_group("${target_name}\\src" FILES ${source_files})
source_group("${target_name}\\inc" FILES ${include_files})

target_include_directories(${target_name} PRIVATE "./include")