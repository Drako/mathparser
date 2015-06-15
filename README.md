# mathparser

This is a little parser library for mathematical expressions.
Through variables and functions it supports some rudimentary functional programming.

It is written in C++11 and has no hard external dependencies so far.

Lets see how far my motivation to bring this to life will stay with me :)

# REQUIREMENTS

* A recent C++ compiler
* CMake (>= 2.8.11)
* (optional) Doxygen for documentation generation

Google Test and Google Mock are bundled with the source code and are only used,
when building the test suite.

# Build & Installation

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DWITH_TESTS=ON -DWITH_EXAMPLE=ON ..
make
make test
[sudo] make install
```

You can use `-DBUILD_SHARED=OFF` to build static libraries which might be neccessary
when you wish to use some of the internal helper class templates.
The installation path can be changed through `-DCMAKE_INSTALL_PREFIX:PATH={wherever you want it}`.

# LICENSE

[MIT License](http://opensource.org/licenses/MIT)

# Travis Build & Test Status

[![Build Status](https://travis-ci.org/Drako/mathparser.svg?branch=master)](https://travis-ci.org/Drako/mathparser)

