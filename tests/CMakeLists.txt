cmake_minimum_required(VERSION 3.25)

file(GLOB_RECURSE SOURCES "*.cxx")
add_executable(tests ${SOURCES})

target_link_libraries(tests PRIVATE GTest::GTest miit)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)

if(DEFINED $<TARGET_FILE_DIR:demo>)
  add_custom_command(TARGET demo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -Et copy $<TARGET_FILE_DIR:demo> $<TARGET_RUNTIME_DLLS:demo>
    COMMAND_EXPAND_LISTS
  )
endif()

include(GoogleTest)
gtest_discover_tests(tests)