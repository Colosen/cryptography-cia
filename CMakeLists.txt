cmake_minimum_required(VERSION 3.30)
project(cryptography_cia)

set(CMAKE_CXX_STANDARD 14)

add_executable(cryptography_cia
    main.cpp
    crypto.cpp
    crypto.h
    matrix.cpp
    matrix.h)
