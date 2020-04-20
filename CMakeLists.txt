cmake_minimum_required(VERSION 3.15...3.17)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
############ Project name and version
set(TEST_MAJOR_VERSION 1)
set(TEST_MINOR_VERSION 0)
set(TEST_PATCH_VERSION 0)
set(TEST_VERSION ${TEST_MAJOR_VERSION}.${TEST_MINOR_VERSION}.${TEST_PATCH_VERSION})
project(SomeRPG VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(
            STATUS "Setting build type to 'RelWithDebInfo' as none was specified.")
    set(CMAKE_BUILD_TYPE
            RelWithDebInfo
            CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui, ccmake
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
            "MinSizeRel" "RelWithDebInfo")
endif()

add_subdirectory(src)