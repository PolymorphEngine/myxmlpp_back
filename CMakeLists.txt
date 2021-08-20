cmake_minimum_required(VERSION 3.17)
project(myxmlpp)

set(CMAKE_CXX_STANDARD 98)

file(GLOB_RECURSE SRCS myxmlpp/*.cpp)
file(GLOB_RECURSE INCS myxmlpp/*.hpp)

include_directories(myxmlpp/include)
include_directories(myxmlpp/include/exceptions)

add_executable(myxmlpp ${SRCS} ${INCS})