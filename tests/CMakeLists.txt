file(GLOB_RECURSE SOURCES "*.cxx")
add_executable(tests ${SOURCES})

target_link_libraries(tests PRIVATE GTest::GTest miit)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)

include(GoogleTest)
gtest_discover_tests(tests)