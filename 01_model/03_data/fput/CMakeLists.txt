
# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

# Activate C++ 11
set (CMAKE_CXX_STANDARD 11)

# Project's name
project(FPUT CXX)

# Set target to RELEASE
set(CMAKE_BUILD_TYPE Release)

# Set the output folder where program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Set the needed source files
set(SOURCE_FILES
    src/core.cpp
    src/core.h
    src/parameters.cpp
    src/parameters.h
    src/simu.cpp)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

find_package (HDF5 COMPONENTS HL CXX REQUIRED)
include_directories(${HDF5_INCLUDE_DIRS})

# Set executable with same name as the project
add_executable(FPUT ${SOURCE_FILES})
target_link_libraries (FPUT Eigen3::Eigen ${HDF5_LIBRARIES})

