cmake_minimum_required(VERSION 3.6)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(bitytskiy_a_o)

include(cmake/build_prefix.cmake)

add_subdirectory(prj.labs)
