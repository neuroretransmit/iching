cmake_minimum_required(VERSION 2.6)
project(iching)

add_executable(iching main.cpp)

install(TARGETS iching RUNTIME DESTINATION bin)
