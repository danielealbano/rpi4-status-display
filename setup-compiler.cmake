if (DEFINED CMAKE_MAKE_PROGRAM)
    message(STATUS "Using make program: ${CMAKE_MAKE_PROGRAM}.")
endif()

if (DEFINED CMAKE_C_COMPILER)
    message(STATUS "Using c compiler: ${CMAKE_C_COMPILER}.")
endif()

if (DEFINED CMAKE_CXX_COMPILER)
    message(STATUS "Using cxx compiler: ${CMAKE_CXX_COMPILER}.")
endif()
