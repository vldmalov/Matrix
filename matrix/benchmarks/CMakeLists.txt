set(target_name "MatrixBenchmarks")
project(MatrixBenchmarks)
message("Build project: ${target_name}")

include("../../externals/google_benchmark.cmake")

file(GLOB_RECURSE source_files "main.cpp" "../source/Matrix.cpp")
file(GLOB_RECURSE include_files "../include/Matrix.h")

set(all_sources ${source_files} ${include_files})
add_executable(${target_name} WIN32 MACOSX_BUNDLE ${all_sources})

source_group("${target_name}\\src" FILES ${source_files})
source_group("${target_name}\\inc" FILES ${include_files})

target_link_libraries(${target_name} PRIVATE benchmark::benchmark)
target_compile_features(${target_name} INTERFACE cxx_std_20)
target_include_directories(${target_name} PRIVATE "../include")