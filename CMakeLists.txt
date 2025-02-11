cmake_minimum_required(VERSION 3.16)
include(FetchContent)

project(cpp-http-backend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SERVER_SOURCES "src/*.cpp")

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBPQ REQUIRED libpq)
pkg_check_modules(LIBPQXX REQUIRED libpqxx)

FetchContent_Declare(httplib SYSTEM
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib
    GIT_TAG a609330e4c6374f741d3b369269f7848255e1954 # v0.14.1
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(httplib)

include_directories(${httplib_SOURCE_DIR})

include_directories(${LIBPQ_INCLUDE_DIRS} ${LIBPQXX_INCLUDE_DIRS})
link_directories(${LIBPQ_LIBRARY_DIRS} ${LIBPQXX_LIBRARY_DIRS})

add_library(etib-http-server SHARED ${SERVER_SOURCES})

find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

target_include_directories(etib-http-server PRIVATE ${LIBPQXX_INCLUDE_DIRS})
target_link_directories(etib-http-server PRIVATE ${LIBPQXX_LIBRARY_DIRS})

target_link_libraries(etib-http-server
    httplib::httplib
    OpenSSL::SSL
    OpenSSL::Crypto
    Threads::Threads
    ${LIBPQ_LIBRARIES}
    ${LIBPQXX_LIBRARIES})