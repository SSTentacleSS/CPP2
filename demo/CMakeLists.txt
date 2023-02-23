add_executable(demo demo.cxx)

target_link_libraries(demo miit)
target_include_directories(demo PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)