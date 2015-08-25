set(test_SOURCES
    main.cxx
    backtracker.cxx
    exception.cxx
    intparser.cxx
    optional.cxx
)

add_executable(mathparser_test_app ${test_SOURCES})
add_executable(mathparser::test ALIAS mathparser_test_app)
target_link_libraries (mathparser_test_app mathparser::lib contrib::gtest contrib::gmock)

ADD_TEST (NAME mathparser_test COMMAND mathparser::test)
