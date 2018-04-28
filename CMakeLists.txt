cmake_minimum_required(VERSION 3.10)

project(plugin_launcher_cpp)

get_filename_component(DEPS_ROOT "${PROJECT_BINARY_DIR}/deps" ABSOLUTE)

#if (MSVC) 
	
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	
	add_subdirectory(googletest)
	
	#include(ExternalProject)
	
	#ExternalProject_Add(googletest
	#  GIT_REPOSITORY https://github.com/google/googletest.git
	#  GIT_TAG master
	#  CMAKE_ARGS -Dgtest_force_shared_crt=ON -DCMAKE_INSTALL_PREFIX=${DEPS_ROOT}
	#)
	
	#include_directories("${DEPS_ROOT}/include")
	#link_directories("${DEPS_ROOT}/lib")
	#link_directories("${DEPS_ROOT}/lib64")

	MESSAGE( STATUS "gtest_SOURCE_DIR:         " ${gtest_SOURCE_DIR} )
	MESSAGE( STATUS "gmock_SOURCE_DIR:         " ${gmock_SOURCE_DIR} )
	MESSAGE( STATUS "plugin_launcher_cpp_SOURCE_DIR:  " ${plugin_launcher_cpp_SOURCE_DIR} )
	

#else(true)
#	find_package(GTest REQUIRED)
#endif(MSVC)

enable_testing()

# Make your header file accessible to the compiler
include_directories(./include)
include_directories(${gtest_SOURCE_DIR}/include)

# Instruct CMake to inspect the following subfolders
add_subdirectory(src)

if (MSVC)
	set_target_properties(plugin_launcher_cpp PROPERTIES COMPILE_FLAGS "/FA" )
endif (MSVC)

# Trivial example using gtest and gmock
#add_executable(cpp_sorter_test test/cpp_sorter_test.cpp)
#target_link_libraries(cpp_sorter_test gtestd gmock_maind)
#add_test(NAME cpp_sorter_test COMMAND cpp_sorter_test)


file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

# from list of files we'll create tests test_name.cpp -> test_name
foreach(_test_file ${TEST_SRC_FILES})
    get_filename_component(_test_name ${_test_file} NAME_WE)
    add_executable(${_test_name} ${_test_file})
    #add_dependencies(${_test_name} "googletest")
    target_link_libraries(${_test_name} gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
    add_test(${_test_name} ${_test_name})
    set_tests_properties(${_test_name} PROPERTIES TIMEOUT 5)
endforeach()