cmake_minimum_required(VERSION 3.16)
project(RPI4_STATUS_DISPLAY LANGUAGES CXX VERSION 0.3)


set(CMAKE_CXX_STANDARD 14)

###
### BUILD INTERNAL LIBRARY FOR BOTH EXECUTABLE AND TESTS
###
include(FindPkgConfig)
pkg_search_module(
        SDL2
        REQUIRED
        sdl2>=2)
message(STATUS "Found SDL2: version ${SDL2_VERSION}")

file(
        GLOB_RECURSE
        RPI4_STATUS_DISPLAY_SRC_FILES
        "${PROJECT_SOURCE_DIR}/src/*.cpp")
list(
        REMOVE_ITEM
        RPI4_STATUS_DISPLAY_SRC_FILES
        "${PROJECT_SOURCE_DIR}/src/main.cpp")

add_library(
        rpi4_status_display_library
        STATIC
        ${RPI4_STATUS_DISPLAY_SRC_FILES})
target_include_directories(
        rpi4_status_display_library
        PUBLIC
        "${PROJECT_SOURCE_DIR}/src"
        ${SDL2_INCLUDE_DIRS})
target_link_libraries(
        rpi4_status_display_library
        PUBLIC
        ${SDL2_LINK_LIBRARIES})
target_link_directories(
        rpi4_status_display_library
        PUBLIC
        ${SDL2_LIBRARY_DIRS})

#target_link_libraries(
#        rpi4_status_display_library
#        PUBLIC
#        bcm2835
#)

###
### BUILD EXECUTABLE
###
add_executable(
        rpi4_status_display
        "src/main.cpp")
add_dependencies(
        rpi4_status_display
        rpi4_status_display_library)
target_link_libraries(
        rpi4_status_display
        PUBLIC
        rpi4_status_display_library
)

###
### BUILD TESTS
###
Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

file(
        GLOB_RECURSE
        RPI4_STATUS_DISPLAY_TESTS_FILES
        "${PROJECT_SOURCE_DIR}/tests/*.cpp")

add_executable(
        rpi4_status_display_tests
        ${RPI4_STATUS_DISPLAY_TESTS_FILES})
add_dependencies(
        rpi4_status_display_tests
        rpi4_status_display_library)
target_link_libraries(
        rpi4_status_display_tests
        rpi4_status_display_library Catch2::Catch2)
