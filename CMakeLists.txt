cmake_minimum_required (VERSION 3.3)
project (long_range_radar)

# The version number.
set (long_range_radar_VERSION_MAJOR 0)
set (long_range_radar_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings
# to the source code
# configure_file (
#   "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
#   "${PROJECT_BINARY_DIR}/TutorialConfig.h"
# )
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# include_directories("${PROJECT_BINARY_DIR}")

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -g")

add_subdirectory(src)
