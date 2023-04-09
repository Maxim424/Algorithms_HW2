cmake_minimum_required(VERSION 3.24)
project(Algorithms_HW2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithms_HW2 main.cpp Executors/ordinary_executor.cpp Executors/ordinary_executor.h Utilities/string_generator.cpp Utilities/string_generator.h Algorithms/naive.cpp Algorithms/naive.h Algorithms/kmp.cpp Algorithms/kmp.h)
