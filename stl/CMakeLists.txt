cmake_minimum_required(VERSION 3.16)

project(stl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stl main.cpp
    vezbi1.cpp
    vezbi2.cpp
    vezbi3.cpp
    vezbi4.cpp
    vezbi5.cpp
    proekt1.cpp
    vezbi6.cpp
    vezbi7.cpp
    vezbi8.cpp
    vezbi9.cpp
    vezbi10.cpp
    vezbi11.cpp
    final.cpp)

include(GNUInstallDirs)
install(TARGETS stl
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
