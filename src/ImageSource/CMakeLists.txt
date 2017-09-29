# Set the name and the supported language of the project
project(TIScamera)

# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 2.8)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


# Use the package PkgConfig to detect libv4l2 headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(V4L2 REQUIRED libv4l2)

# Setup CMake to use libv4l2, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${V4L2_INCLUDE_DIRS})
link_directories(${V4L2_LIBRARY_DIRS})

# Add other flags to the compiler
add_definitions(${V4L2_CFLAGS_OTHER})

# Opencv 
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

#Include library
include_directories(include)

# Add an library compiled from main.cpp v4ldevice.cpp ImageSource.cpp
add_library(TIScamera v4ldevice.cpp ImageSource.cpp)

# Link the target to the GTK+ libraries
target_link_libraries(TIScamera ${V4L2_LIBRARIES})
target_link_libraries(TIScamera ${OpenCV_LIBS})





