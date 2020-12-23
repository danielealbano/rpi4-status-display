###
### BUILD INTERNAL LIBRARY FOR BOTH EXECUTABLE AND TESTS
###

include(FindPkgConfig)

# Collect the files required by the internal static library (everything but main.cpp in the root of the sources)
file(
        GLOB_RECURSE
        RPI4_STATUS_DISPLAY_SRC_FILES
        "${PROJECT_SOURCE_DIR}/src/*.cpp")
list(
        REMOVE_ITEM
        RPI4_STATUS_DISPLAY_SRC_FILES
        "${PROJECT_SOURCE_DIR}/src/main.cpp")

if (USE_SDL2)
    pkg_search_module(
            SDL2
            REQUIRED
            sdl2>=2)
    message(STATUS "Found SDL2: version ${SDL2_VERSION}")
else()
    list(
            REMOVE_ITEM
            RPI4_STATUS_DISPLAY_SRC_FILES
            "${PROJECT_SOURCE_DIR}/src/Graphics/Renderer/SdlRenderer.cpp"
            "${PROJECT_SOURCE_DIR}/src/Graphics/Renderer/SdlRenderer.h")
endif()

# Setup the internal static library
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

# Setup the exeutable target
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
