cmake_minimum_required(VERSION 3.20)
project(grade2dshk)

set(CMAKE_CXX_STANDARD 14)

add_executable(grade2dshk#[[Tests/LinearTest.cpp ]] Tests/ChainTest.cpp Linear/MyArray.h Chain/MyChain.h Utils/utils.h)
