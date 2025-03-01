cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(CppRobots)

set(CMAKE_CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "--coverage")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin CACHE FILEPATH "Where to put the binaries.")
set(CMAKE_DOC_OUTPUT_DIR ${CMAKE_BINARY_DIR}/doc CACHE FILEPATH "Where to put the documentation.")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib CACHE FILEPATH "Where to put the libraries.")

set(GTEST_ROOT "${CMAKE_SOURCE_DIR}/googletest" CACHE FILEPATH "Where to googletest is installed")

set(AUTOGEN_WARNING "This file was generated automatically by cmake. Changes to this file will be lost if the code is regenerated.")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_BINARY_DIR}/include)

subdirs(src)
subdirs(doc)
subdirs(EXCLUDE_FROM_ALL test)
