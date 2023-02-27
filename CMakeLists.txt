cmake_minimum_required(VERSION 3.25)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
project(miit VERSION 1.0.0 DESCRIPTION "A library that implements the basic functions required for RUT MIIT")

find_package(GTest REQUIRED)
enable_testing()

add_subdirectory(demo)
add_subdirectory(tests)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/lib")

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_library(miit SHARED ${SOURCES})

set_target_properties(miit PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(miit PROPERTIES SOVERSION 2)
set_target_properties(miit PROPERTIES PUBLIC_HEADER include/lib.h)

target_include_directories(miit PRIVATE include)
target_include_directories(miit PRIVATE src)

include(GNUInstallDirs)
include(GenerateExportHeader)

generate_export_header(miit)
install(FILES ${CMAKE_BINARY_DIR}/miit.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
install(
  TARGETS miit
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

configure_file(miit.pc.in miit.pc @ONLY)