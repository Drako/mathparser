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
target_compile_features(mathparser_test_app PRIVATE cxx_auto_type)

add_test(NAME mathparser_test COMMAND mathparser::test)
