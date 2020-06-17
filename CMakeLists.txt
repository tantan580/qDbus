set(TARGET_PATH "${CMAKE_INSTALL_PREFIX}/bin")
project(dbus-demo)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_subdirectory(server)
add_subdirectory(client)


