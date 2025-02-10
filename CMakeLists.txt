cmake_minimum_required(VERSION 3.16)
include(FetchContent)

# Set the project name
project(cpp-http-backend)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Find all source files for the server and client
file(GLOB SERVER_SOURCES "src/*.cpp")

FetchContent_Declare(httplib SYSTEM
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib
    GIT_TAG a609330e4c6374f741d3b369269f7848255e1954 # v0.14.1
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(httplib)

include_directories(${httplib_SOURCE_DIR})

# Add the server library as a shared library
add_library(etib-http-server SHARED ${SERVER_SOURCES})

# Find required packages
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

# Link libraries for server and client
target_link_libraries(etib-http-server
    httplib::httplib
    OpenSSL::SSL
    OpenSSL::Crypto
    Threads::Threads)