cmake_minimum_required(VERSION 3.24)
project(webserver)

# Set Compiler Flags
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wextra -Werror -pedantic-errors")

# Include project headers
include_directories(./include)

# Use all other files as a static library for main
add_library(Core STATIC)
add_subdirectory(./src/api)
add_subdirectory(./src/db)

# Put executables in `pwd`/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Use POSIX
add_definitions(-D_POSIX_C_SOURCE=200809L)

# Create Testing Executable
add_executable(testing)
add_subdirectory(./tests)
add_dependencies(testing Core)
target_link_libraries(testing PRIVATE Core)

# Create Program Executable
set(BASE_FILES src/main.c)
add_executable(server ${BASE_FILES})
add_dependencies(server Core)
target_link_libraries(server PRIVATE Core)

