PROJECT ( mathparser )
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8.11 )

# customizations
OPTION ( BUILD_SHARED "Build shared library" ON )
OPTION ( WITH_EXAMPLE "Build the example" OFF )
OPTION ( WITH_TESTS "Build tests" OFF )

IF ( BUILD_SHARED )
    SET ( LIBRARY_TYPE SHARED )
ELSE ()
    SET ( LIBRARY_TYPE STATIC )
ENDIF ()

# external dependencies
IF ( WITH_TESTS )
    FIND_PACKAGE ( Threads REQUIRED )
ENDIF ()

# bundled dependencies
ADD_SUBDIRECTORY ( contrib )

# the mathparser library
ADD_SUBDIRECTORY ( mathparser )

# an example command line program
IF ( WITH_EXAMPLE )
    ADD_SUBDIRECTORY ( example )
ENDIF ()

# the tests
IF ( WITH_TESTS )
    ENABLE_TESTING ()
    ADD_SUBDIRECTORY ( tests )
ENDIF ()

