cmake_minimum_required (VERSION 3.1.0)
set(CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 20)

project(visitor_exerciese VERSION 0.1.0)

add_executable(visitor_exerciese cvisitor.cpp classical.h lambda_visotor.h)