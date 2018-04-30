file(GLOB SOURCES "*.cpp")

add_library(plugin_launcher_library "${SOURCES}")

add_executable (plugin_launcher_cpp "main.cpp")

target_link_libraries (plugin_launcher_cpp plugin_launcher_library)

set_target_properties(plugin_launcher_library PROPERTIES PUBLIC_HEADER "../include/mygenericclass.hpp")
install(TARGETS plugin_launcher_library 
        DESTINATION lib 
		EXPORT plugin_launcher_library-targets
		PUBLIC_HEADER DESTINATION include)
install(EXPORT plugin_launcher_library-targets
        DESTINATION lib/myproj)

install(TARGETS plugin_launcher_cpp 
        DESTINATION bin 
		EXPORT plugin_launcher_cpp-targets)
install(EXPORT plugin_launcher_cpp-targets 
        DESTINATION bin/myproj)