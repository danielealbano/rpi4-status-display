cmake_minimum_required(VERSION 3.16)
project(RPI4_STATUS_DISPLAY LANGUAGES CXX VERSION 0.3)

set(CMAKE_CXX_STANDARD 14)

include(setup-options.cmake)
include(setup-build-opts.cmake)

include(src/src.cmake)

if (BUILD_TESTS)
include(tests/tests.cmake)
endif()
