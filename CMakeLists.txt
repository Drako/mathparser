cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 NEW)

project(mathparser)

option(WITH_EXAMPLE "Build the example" OFF)
option(WITH_TESTS "Build tests" OFF)

# external dependencies
find_package(Doxygen)

# bundled dependencies
add_subdirectory(contrib)

# the mathparser library
add_subdirectory(mathparser)

# an example command line program
if(WITH_EXAMPLE)
    add_subdirectory(example)
endif(WITH_EXAMPLE)

# the tests
if(WITH_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif(WITH_TESTS)

# documentation
if(DOXYGEN_FOUND)
    configure_file(Doxyfile.in Doxyfile)
    add_custom_target(doc "${DOXYGEN_EXECUTABLE}" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Generating documentation with Doxygen." VERBATIM
    )
endif(DOXYGEN_FOUND)
