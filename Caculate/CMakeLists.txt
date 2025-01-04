cmake_minimum_required(VERSION 3.28)
project(Caculate)

set(CMAKE_CXX_STANDARD 17)

add_executable(Caculate main.cpp
        Model/File/File.h
        Model/File/File.cpp
        Constant/Common.cpp
        Constant/Common.h
        Model/File/File.cpp
        Model/Calculation/Calculations.cpp
        Model/Calculation/Calculations.h)
