# Preprocessor Exercises

Implements:
- Exercise 5.1: language-selectable hello using preprocessor conditionals, split into lib + exe.
- Exercise 5.2: `super_assert` macro with TRACE / PERMISSIVE / VERBOSE and `NDEBUG` handling.

## Build

```bash
cmake -S . -B build -DLANGUAGE=EN    or  -DLANGUAGE=ES
cmake --build build
./build/main
