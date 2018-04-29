cmake_minimum_required(VERSION 3.10)

project(plugin_launcher_cpp)

#use CMAKE_PREFIX_PATH environment variable to specify path location wtih all necessary dependencies
find_package(GTest REQUIRED)

enable_testing()

# Make your header file accessible to the compiler
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./include)

# Instruct CMake to inspect the following subfolders
add_subdirectory(src)

if (MSVC)
	set_target_properties(plugin_launcher_cpp PROPERTIES COMPILE_FLAGS "/FA" )
endif (MSVC)

# Trivial example using gtest and gmock
add_executable(cpp_sorter_test test/cpp_sorter_test.cpp)
target_link_libraries(cpp_sorter_test ${GTEST_BOTH_LIBRARIES})
add_test(NAME cpp_sorter_test COMMAND cpp_sorter_test)


#file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

# from list of files we'll create tests test_name.cpp -> test_name
#foreach(_test_file ${TEST_SRC_FILES})
#    get_filename_component(_test_name ${_test_file} NAME_WE)
#    add_executable(${_test_name} ${_test_file})
    #add_dependencies(${_test_name} "googletest")
#    target_link_libraries(${_test_name} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
#    add_test(${_test_name} ${_test_name})
#    set_tests_properties(${_test_name} PROPERTIES TIMEOUT 5)
#endforeach()