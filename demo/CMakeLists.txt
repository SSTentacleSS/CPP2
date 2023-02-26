cmake_minimum_required(VERSION 3.25)

add_executable(demo demo.cxx)

target_link_libraries(demo miit)
target_include_directories(demo PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../include)

if(WIN32)
  add_custom_command(TARGET demo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:miit> $<TARGET_FILE_DIR:demo>
    COMMAND_EXPAND_LISTS
  )
endif()