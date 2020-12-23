# Include the FetchContent module to get Catch directly from the git repository
Include(FetchContent)

# Disable catch self-testing build
SET(CATCH_BUILD_TESTING OFF CACHE BOOL "CATCH_BUILD_TESTING")
SET(CATCH_INSTALL_DOCS OFF CACHE BOOL "CATCH_INSTALL_DOCS")

# Fetch Catch2
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)
FetchContent_MakeAvailable(Catch2)

# Collect the c++ test files
file(
        GLOB_RECURSE
        RPI4_STATUS_DISPLAY_TESTS_FILES
        "${PROJECT_SOURCE_DIR}/tests/*.cpp")

if (USE_SDL2)
    # Do nothing
else()
    list(
            REMOVE_ITEM
            RPI4_STATUS_DISPLAY_TESTS_FILES
            "${PROJECT_SOURCE_DIR}/tests/Graphics/Renderer/SdlRenderer.cpp")
endif()

# Setup the tests executable target
add_executable(
        rpi4_status_display_tests
        ${RPI4_STATUS_DISPLAY_TESTS_FILES})
add_dependencies(
        rpi4_status_display_tests
        rpi4_status_display_library)
target_link_libraries(
        rpi4_status_display_tests
        rpi4_status_display_library Catch2::Catch2)
