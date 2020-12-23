add_compile_options($<$<COMPILE_LANGUAGE:C>:-g>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-g>)

add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fstack-protector-strong>)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG=1)

    add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-O0>)
    add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-inline>)
    add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fno-omit-frame-pointer>)

    # gcov linking required by gcc
    if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
        link_libraries(gcov)
    endif()

    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-generate -fprofile-arcs -ftest-coverage --coverage")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-generate -fprofile-arcs -ftest-coverage --coverage")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fprofile-generate -fprofile-arcs -ftest-coverage --coverage")
    set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fprofile-generate -fprofile-arcs -ftest-coverage --coverage")
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions(-DNDEBUG=1)

    add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-O3>)
else()
    message(FATAL_ERROR "Unsupported build type ${CMAKE_BUILD_TYPE}, the only support build types are Debug and Release")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
