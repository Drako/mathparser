configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/mathparser/config.hxx.in
    ${CMAKE_CURRENT_SOURCE_DIR}/mathparser/config.hxx
)

set(mp_SOURCES
    exception.cxx
)

set(mp_HEADERS
    mathparser/backtracker.hxx
    mathparser/config.hxx
    mathparser/exception.hxx
    mathparser/intparser.hxx
    mathparser/optional.hxx
)

add_library(mathparser STATIC ${mp_SOURCES} ${mp_HEADERS})
add_library(mathparser::lib ALIAS mathparser)

target_include_directories(mathparser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(mathparser
    PUBLIC cxx_explicit_conversions cxx_nullptr cxx_rvalue_references
)

install(
    TARGETS mathparser
    RUNTIME DESTINATION lib
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
install(FILES ${mp_HEADERS} DESTINATION include/mathparser)
