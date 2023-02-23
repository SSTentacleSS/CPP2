cmake_minimum_required(VERSION 3.25)

project(miit VERSION 1.0.0 DESCRIPTION "A library that implements the basic functions required for RUT MIIT")
add_subdirectory(demo)

add_library(
  miit SHARED
  src/lib.cpp
  includes/lib.hpp
)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib CACHE PATH "Directory for libraries")
set_target_properties(miit PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(miit PROPERTIES SOVERSION 0)
set_target_properties(miit PROPERTIES PUBLIC_HEADER include/lib.h)

target_include_directories(miit PRIVATE includes)
target_include_directories(miit PRIVATE src)

include(GNUInstallDirs)

install(FILES ${CMAKE_BINARY_DIR}/miit.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
install(
  TARGETS miit
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

configure_file(miit.pc.in miit.pc @ONLY)