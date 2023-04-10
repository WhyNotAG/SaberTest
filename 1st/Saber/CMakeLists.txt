cmake_minimum_required(VERSION 3.25)
project(Saber)

set(CMAKE_CXX_STANDARD 17)

add_executable(Saber main.cpp private/ListNode.cpp public/ListNode.h private/ListRand.cpp public/ListRand.h)
