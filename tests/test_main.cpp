// test_main.cpp
//
// Boots Catch2. The macro CATCH_CONFIG_MAIN tells Catch2 to generate the
// main() function for the test executable — meaning we don't write our own.
//
// All actual TEST_CASE blocks will live in separate files (test_vault.cpp,
// test_credential.cpp, etc.). Keeping the bootstrap in its own file means
// Catch2's main is compiled only once, which keeps recompilation fast as
// the test suite grows.

#define CATCH_CONFIG_MAIN
#include "catch.hpp"