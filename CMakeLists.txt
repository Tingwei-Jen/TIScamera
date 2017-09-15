# Set the name and the supported language of the project
project(TIScamera)

# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 2.8)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GST REQUIRED gstreamer-1.0)
pkg_check_modules(GSTvideo REQUIRED gstreamer-video-1.0)
pkg_check_modules(GOB REQUIRED gobject-introspection-1.0)
pkg_check_modules(TCAM REQUIRED tcam)


# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

include_directories(${GST_INCLUDE_DIRS})
link_directories(${GST_LIBRARY_DIRS})

include_directories(${GSTvideo_INCLUDE_DIRS})
link_directories(${GSTvideo_LIBRARY_DIRS})

include_directories(${GOB_INCLUDE_DIRS})
link_directories(${GOB_LIBRARY_DIRS})

include_directories(${TCAM_INCLUDE_DIRS})
link_directories(${TCAM_LIBRARY_DIRS})

# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER})
add_definitions(${GST_CFLAGS_OTHER})
add_definitions(${GSTvideo_CFLAGS_OTHER})
add_definitions(${GOB_CFLAGS_OTHER})
add_definitions(${TCAM_CFLAGS_OTHER})

# Opencv 
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )


# Add an executable compiled from test.cpp
add_executable(TIScamera main.cpp)

# Link the target to the GTK+ libraries
target_link_libraries(TIScamera ${GTK3_LIBRARIES})
target_link_libraries(TIScamera ${GST_LIBRARIES})
target_link_libraries(TIScamera ${GSTvideo_LIBRARIES})
target_link_libraries(TIScamera ${GOB_LIBRARIES})
target_link_libraries(TIScamera ${TCAM_LIBRARIES})


target_link_libraries(TIScamera ${OpenCV_LIBS})





