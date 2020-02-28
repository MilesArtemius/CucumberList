cmake_minimum_required(VERSION 3.16)
project(CucumberList)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE sources stack/* list/*)

add_executable(CucumberList ${sources})