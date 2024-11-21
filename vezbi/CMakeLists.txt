cmake_minimum_required(VERSION 3.16)

project(vezbi LANGUAGES C)

add_executable(vezbi main.c
    vezhbi01.c
    vezhbi03.c
    vezhbi04.c
    vezhbi05.c
    vezhbi06.c
    vezhbi07.c
    vezhbi08.c
    proekt1.c
    zadaci.c
    proekt2.c
    proekt3.c
    vezhbi11.c
    vezhbi12.c
    proekt4.c
    datoteki1.c
    vezhbi13.c
    vezhbi13_2.c
    datoteki2.c)

include(GNUInstallDirs)
install(TARGETS vezbi
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
