cmake_minimum_required(VERSION 3.25)

file(GLOB_RECURSE SOURCES "*.cxx")
add_executable(tests ${SOURCES})

target_link_libraries(tests PRIVATE GTest::GTest miit)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)

if(WIN32)
  add_custom_command(TARGET tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:miit> $<TARGET_FILE_DIR:tests>
    COMMAND_EXPAND_LISTS
  )
endif()

include(GoogleTest)
gtest_discover_tests(tests)