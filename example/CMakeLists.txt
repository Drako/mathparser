add_executable(parsemath main.cxx)
add_executable(mathparser::example ALIAS parsemath)

target_link_libraries(parsemath PRIVATE mathparser)
