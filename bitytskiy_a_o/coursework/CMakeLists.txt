cmake_minimum_required(VERSION 3.1)

project(CreditCalculator)

set (CMAKE_PREFIX_PATH "C:/Qt/5.12.0/msvc2017_64/")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Widgets CONFIG REQUIRED)

add_subdirectory(credit_calculator)

