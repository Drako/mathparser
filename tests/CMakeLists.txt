FILE ( GLOB_RECURSE test_SOURCES *.cxx )
FILE ( GLOB_RECURSE test_HEADERS *.hxx )

INCLUDE_DIRECTORIES ( ../mathparser )
INCLUDE_DIRECTORIES ( ../contrib/gtest/include )
INCLUDE_DIRECTORIES ( ../contrib/gmock/include )

ADD_EXECUTABLE ( mathparser_test_app ${test_SOURCES} ${test_HEADERS} )
TARGET_LINK_LIBRARIES ( mathparser_test_app mathparser gtest gmock )

ADD_TEST ( NAME mathparser_test COMMAND mathparser_test_app )

