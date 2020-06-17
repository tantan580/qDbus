set(TARGET_PATH "${CMAKE_INSTALL_PREFIX}/bin")
set(TARGET_NAME "dbusdemo-server")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5DBus REQUIRED)

add_executable(
    ${TARGET_NAME}
    person.h
    person.cpp
    main.cpp
)

target_link_libraries(
    ${TARGET_NAME}
    Qt5::Core
    Qt5::DBus
)
install_targets("/bin" dbusdemo-server)
