cmake_minimum_required(VERSION 3.8)
project(sdk_gcc)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ecs/lib/lib_io.h
        ecs/lib/lib_time.h
        ecs/CPoint.h
        ecs/ecs.cpp
        ecs/head.h
        ecs/io.cpp
        ecs/Linear_shuai.h
        ecs/LinearRegression.cpp
        ecs/LinearRegression.h
        ecs/mat.h
        ecs/Method.h
        ecs/predict.cpp
        ecs/predict.h
        ecs/source.h
        ecs/Utils.cpp
        ecs/Utils.h)

add_executable(sdk_gcc ${SOURCE_FILES})