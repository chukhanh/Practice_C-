cmake_minimum_required(VERSION 3.28)
project(ProfilePage)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProfilePage main.cpp
        Model/Student/Student.cpp
        Model/Student/Student.h
        Constant/Common.h
        Model/File/File.cpp
        Model/File/File.h
        Constant/Common.cpp)
