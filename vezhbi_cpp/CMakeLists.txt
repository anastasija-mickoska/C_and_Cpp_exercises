cmake_minimum_required(VERSION 3.16)

project(vezhbi_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vezhbi_cpp #[[vezbi1.cpp
    klasi.cpp
    klasi3.cpp
    klasi2.cpp
    vezbi6.cpp
    operatori.cpp
    operatori2.cpp
    operatori3.cpp
    nasleduvanje.cpp
    nasleduvanje2.cpp
    proekt2.cpp]]
    # nasleduvanje3.cpp
    polimorfizam.cpp
)

include(GNUInstallDirs)
install(TARGETS vezhbi_cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
