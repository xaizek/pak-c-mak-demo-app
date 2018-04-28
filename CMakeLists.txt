cmake_minimum_required(VERSION 3.10)

project(plugin_launcher_cpp)

# Make your header file accessible to the compiler
include_directories(./include)

# Instruct CMake to inspect the following subfolders
add_subdirectory(src)

if (MSVC)
	set_target_properties(plugin_launcher_cpp PROPERTIES COMPILE_FLAGS "/FA" )
endif (MSVC)

