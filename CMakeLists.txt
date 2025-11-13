# CMake minimum version. Change range if using unsupported CMake version.
cmake_minimum_required(VERSION 3.14...3.27)

# Project name, description, and language (C vs. CPP).
project(Milestone3_final
        DESCRIPTION "Milestone 3"
        LANGUAGES CXX)

# Set C++ version to use.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch JSON parsing library from GitHub.
include(FetchContent)
FetchContent_Declare(json URL
        https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

# Fetch Google Test library from GitHub.
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Print message to check if JSON is correctly fetched
message(STATUS "Json library fetched: ${json_SOURCE_DIR}")

# Print message to check if Google Test is correctly fetched
message(STATUS "Google Test library fetched: ${googletest_SOURCE_DIR}")

# Declare the main executable
add_executable(Milestone3_final
        milestone3.cpp
        cache_manager.cpp
        doubly_linked_list.cpp
        hash_table.cpp
        hash_node.cpp
        dll_node.cpp
)

# Link external libraries (JSON library) to the main executable.
target_link_libraries(Milestone3_final PRIVATE
        nlohmann_json::nlohmann_json
)

# Copy `.json` files into the build directory.
add_custom_command(TARGET Milestone3_final PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/*.json $<TARGET_FILE_DIR:Milestone3_final>)

# Add the necessary include directory for JSON
target_include_directories(Milestone3_final PRIVATE ${json_SOURCE_DIR}/single_include)

# Declare the test executable
add_executable(runTests
        test_cache_manager.cpp
        test_doubly_linked_list.cpp

)

# Link Google Test libraries to the test executable
target_link_libraries(runTests PRIVATE
        gtest_main
        nlohmann_json::nlohmann_json
)

# Add the necessary include directory for Google Test
target_include_directories(runTests PRIVATE ${googletest_SOURCE_DIR}/googletest/include)

# Enable testing and add the test
enable_testing()
add_test(NAME runTests COMMAND runTests)

# Optionally, link the gtest library to the test executable manually:
target_link_libraries(runTests PRIVATE gtest gtest_main)
