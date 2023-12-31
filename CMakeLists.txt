cmake_minimum_required(VERSION 3.26)
project(WhiteSpaceRemover)

set(CMAKE_CXX_STANDARD 23)

option(BUILD_SHARED_LIB "Build shared library" OFF)
option(BUILD_STATIC_LIB "Build static library" OFF)

if(MSVC)
    add_compile_options(/W4 /WX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /Zi")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
elseif(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
    if(NOT CMAKE_BUILD_TYPE MATCHES Debug)
        set(CMAKE_EXE_LINKER_FLAGS "-static")
    endif()
endif()

file(GLOB_RECURSE LIB_SOURCES "sources/*.cpp")

if(BUILD_SHARED_LIB)
    add_library(WhiteSpaceRemover SHARED ${LIB_SOURCES})
elseif(BUILD_STATIC_LIB)
    add_library(WhiteSpaceRemover STATIC ${LIB_SOURCES})
else()
    add_executable(WhiteSpaceRemover main.cpp ${LIB_SOURCES})
endif()
target_include_directories(WhiteSpaceRemover PRIVATE
        "./includes"
        "./includes/interfaces"
)
