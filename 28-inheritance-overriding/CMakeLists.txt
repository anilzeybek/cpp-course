cmake_minimum_required(VERSION 3.10)
project(28_inheritance_overriding)

set(CMAKE_CXX_STANDARD 14)

add_executable(28_inheritance_overriding main.cpp Account.cpp Account.h Savings_Account.cpp Savings_Account.h)