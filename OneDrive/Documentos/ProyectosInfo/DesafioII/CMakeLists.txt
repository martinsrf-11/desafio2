cmake_minimum_required(VERSION 3.16)

project(DesafioII LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DesafioII main.cpp
    usuario.h usuario.cpp
    huesped.h huesped.cpp
    anfitrion.h anfitrion.cpp
    alojamiento.h alojamiento.cpp
    reservacion.h reservacion.cpp)

include(GNUInstallDirs)
install(TARGETS DesafioII
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
