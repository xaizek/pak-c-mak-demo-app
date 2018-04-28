cmake_minimum_required(VERSION 3.10)

project(plugin_launcher_cpp)

enable_testing()
if (MSVC) 
	include(ExternalProject)
	ExternalProject_Add(googletest
	  GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG release-1.8.0
	  BINARY_DIR        "${CMAKE_BINARY_DIR}/googletest-build"
	  CONFIGURE_COMMAND ""
	  BUILD_COMMAND     ""
	  INSTALL_COMMAND   ""
	  TEST_COMMAND      ""
	)
else(true)
	find_package(GTest REQUIRED)
endif(MSVC)

# Make your header file accessible to the compiler
include_directories(./include)

# Instruct CMake to inspect the following subfolders
add_subdirectory(src)

if (MSVC)
	set_target_properties(plugin_launcher_cpp PROPERTIES COMPILE_FLAGS "/FA" )
endif (MSVC)
