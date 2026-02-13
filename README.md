# Realtime Accelerated Renderer for Equations (RARE)
RARE is a C++ library for realtime rendering of equations.
It takes an [OASIS](https://github.com/open-algebra/oasis) expression tree as input and provides the necessary vertex buffers and shaders to render it.

## Build Instructions
RARE uses C++23, therefore a recent compiler is required. RARE is known to work with Clang 21 or newer.
Additionally the following are required:
- [CMake](https://cmake.org/)
- [Catch2](https://github.com/catchorg/Catch2)* for unit testing. (optional)
- [SDL3](https://www.libsdl.org/)* for the sample application. (optional)

<small>*can be downloaded at configure time automatically by CMake</small>

## Features
- Realtime rendering of mathematical expressions
- Support for a wide range of mathematical functions and operators
- Customizable shaders for advanced rendering techniques (e.g. signed distance field rendering)
- Integration with OASIS for seamless expression tree handling

## Contributing Guidelines
See the [OASIS Contributing Guidelines](https://github.com/open-algebra/oasis/blob/master/CONTRIBUTING.md)

## Code Of Conduct
See the [OASIS Code Of Conduct](https://github.com/open-algebra/oasis/blob/master/CODE_OF_CONDUCT.md)