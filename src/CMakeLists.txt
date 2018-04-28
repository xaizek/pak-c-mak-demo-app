file(GLOB SOURCES "*.cpp")

add_library(plugin_launcher_library "${SOURCES}")

add_executable (plugin_launcher_cpp "main.cpp")

target_link_libraries (plugin_launcher_cpp plugin_launcher_library)