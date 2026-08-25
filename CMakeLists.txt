cmake_minimum_required(VERSION 3.20)

project(
    mikis13_ps5_lab
    VERSION 3.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    mikis13-ps5

    src/main.cpp
    src/elf_info.cpp
    src/virtual_memory.cpp
    src/decoder.cpp
    src/syscall.cpp
    src/gpu.cpp
    src/shader.cpp
    src/input.cpp
    src/debugger.cpp
)

target_include_directories(
    mikis13-ps5
    PRIVATE
    include
)

enable_testing()

add_test(
    NAME info_test
    COMMAND mikis13-ps5 info
)

add_test(
    NAME core_selftest
    COMMAND mikis13-ps5 selftest
)
