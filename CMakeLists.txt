PROJECT ( mathparser )
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8.11 )

LIST ( APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/cxx11"
)
INCLUDE ( CheckCxx11 )
CXX11_REQUIRE_FEATURES ()

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
FIND_PACKAGE ( Doxygen )

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

# documentation
IF ( DOXYGEN_FOUND )
    CONFIGURE_FILE ( Doxyfile.in Doxyfile )
    ADD_CUSTOM_TARGET ( doc "${DOXYGEN_EXECUTABLE}" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Generating documentation with Doxygen." VERBATIM
    )
ENDIF ()
