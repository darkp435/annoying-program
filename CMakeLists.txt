cmake_minimum_required(VERSION 3.20)

project(Antiproductivity LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Antiproductivity WIN32 main.cpp annoying_prompt.cpp)

if(MINGW)
    target_link_options(Antiproductivity PRIVATE
        -mwindows
        -municode
    )
endif()