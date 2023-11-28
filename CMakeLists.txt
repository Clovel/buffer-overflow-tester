#
#                     Copyright (C) 2023 Clovis Durand
#
# -----------------------------------------------------------------------------

# CMake version required ----------------------------------
cmake_minimum_required(VERSION 3.10)

# Project definition --------------------------------------
project(SecurityTest VERSION "1.0.0")

#------------------------------------------------------------------------------
# Build definition (to do before calling 'project()')
#------------------------------------------------------------------------------

# Build type
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Release CACHE STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
    FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG=1)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

message(STATUS "Build type is : ${CMAKE_BUILD_TYPE}")

# CASE OF C PROJECT
set(CMAKE_C_STANDARD 99)
if(NOT CMAKE_C_FLAGS)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32 -fno-stack-protector -z execstack -Wall -Wextra -Wformat-security -pedantic" CACHE STRING "C99 compilation flags" FORCE)
endif(NOT CMAKE_C_FLAGS)

# CASE OF CPP PROJECT
set(CMAKE_CXX_STANDARD 17)
if(NOT CMAKE_CXX_FLAGS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32 -fno-stack-protector -z execstack -Wall -Wextra -Wformat-security -pedantic" CACHE STRING "C++17 compilation flags" FORCE)
endif(NOT CMAKE_CXX_FLAGS)

#------------------------------------------------------------------------------
# Project definition, variable and dependencies
#------------------------------------------------------------------------------

set(CMAKE_PROJECT_NAME ${PROJECT_NAME})
set(CMAKE_SYSTEM_NAME Linux)

set(CMAKE_PROJECT_BRIEF "buffer overflow test-bench")

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    if(NOT INSTALL_DESTINATION_SET)
        set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/dest CACHE PATH "" FORCE)
        set(INSTALL_DESTINATION_SET TRUE)
    endif(NOT INSTALL_DESTINATION_SET)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

#------------------------------------------------------------------------------
# Project configuration
#------------------------------------------------------------------------------

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#------------------------------------------------------------------------------
# Sub-directories
#------------------------------------------------------------------------------

# Main build
add_subdirectory(src)
