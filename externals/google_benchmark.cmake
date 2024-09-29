message("External Dependency: Google Benchmark")

set(REPO_PATH "https://github.com/google/benchmark.git")
set(VERSION_TAG "v1.9.0")

include(FetchContent)
FetchContent_Declare(
    benchmark
    GIT_REPOSITORY ${REPO_PATH}
    GIT_TAG ${VERSION_TAG}
)

FetchContent_MakeAvailable(benchmark)