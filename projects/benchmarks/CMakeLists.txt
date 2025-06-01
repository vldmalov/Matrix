set(target_name "MatrixBenchmarks")
project(MatrixBenchmarks LANGUAGES CXX)
message("Build project: ${target_name}")

include("../../externals/google_benchmark.cmake")

file(GLOB_RECURSE source_files "main.cpp" "../matrix/source/Matrix.cpp" "../matrix/source/MatrixUtils.cpp")
file(GLOB_RECURSE include_files "../matrix/include/Matrix.h" "../matrix/source/MatrixUtils.h")

set(all_sources ${source_files} ${include_files})
add_executable(${target_name} MACOSX_BUNDLE ${all_sources})

source_group("${target_name}\\src" FILES ${source_files})
source_group("${target_name}\\inc" FILES ${include_files})

target_include_directories(${target_name} PRIVATE "../matrix/include")
target_link_libraries(${target_name} PRIVATE benchmark::benchmark)
target_compile_features(${target_name} INTERFACE cxx_std_20)