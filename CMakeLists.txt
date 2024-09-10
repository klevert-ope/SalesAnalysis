cmake_minimum_required(VERSION 3.25)
project(SalesAnalysis)

set(CMAKE_CXX_STANDARD 20)

add_executable(SalesAnalysis
        main.cpp
        SalesRecord.h
        DataParser.cpp
        DataParser.h
        SalesAnalysis.cpp
        SalesAnalysis.h)
