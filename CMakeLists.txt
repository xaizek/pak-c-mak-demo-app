cmake_minimum_required(VERSION 2.6.4)

project(pak_c_mak_demo_app)

#use CMAKE_PREFIX_PATH environment variable to specify path location wtih all necessary dependencies
find_package(GTest REQUIRED)

enable_testing()

# Make your header file accessible to the compiler
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(./include)

# Bulding and Compiling sources
file(GLOB SOURCES "src/*.cpp")

add_library(pak_c_mak_demo_app_library ${SOURCES})

add_executable (pak_c_mak_demo_app_executable "src/main.cpp")

target_link_libraries (pak_c_mak_demo_app_executable pak_c_mak_demo_app_library)		


# Running unit tests with gtest
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

if (NOT WIN32)
    set(PTHREAD_LIB_PATH pthread)
endif (WIN32)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
endif ()

# from list of files we'll create tests test_name.cpp -> test_name
foreach(_test_file ${TEST_SRC_FILES})
    get_filename_component(_test_name ${_test_file} NAME_WE)
    add_executable(${_test_name} ${_test_file})
    target_link_libraries(${_test_name} ${GTEST_BOTH_LIBRARIES} pak_c_mak_demo_app_library ${PTHREAD_LIB_PATH})
    add_test(${_test_name} ${_test_name})
    set_tests_properties(${_test_name} PROPERTIES TIMEOUT 5)
endforeach()


# Installing build artifacts
set_target_properties(pak_c_mak_demo_app_library PROPERTIES PUBLIC_HEADER "include/myholderclass.hpp")
install(TARGETS pak_c_mak_demo_app_library 
        DESTINATION lib 
		EXPORT pak_c_mak_demo_app_library-targets
		PUBLIC_HEADER DESTINATION include)
install(EXPORT pak_c_mak_demo_app_library-targets
        DESTINATION lib/pak_c_mak_demo_app)

install(TARGETS pak_c_mak_demo_app_executable 
        DESTINATION bin 
		EXPORT pak_c_mak_demo_app_executable-targets)
install(EXPORT pak_c_mak_demo_app_executable-targets 
        DESTINATION bin/pak_c_mak_demo_app)
