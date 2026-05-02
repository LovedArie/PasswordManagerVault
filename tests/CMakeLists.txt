# Test executable. Uses Catch2 v2 (header-only, in include/catch.hpp).
# We'll add more test_*.cpp files here as we add classes — for now just
# the bootstrap file so we can verify the test framework compiles.

add_executable(tests
    test_main.cpp
    test_vault.cpp
    test_entry.cpp
)

target_link_libraries(tests PRIVATE domain)

# Register with CTest so `ctest` from the build folder runs our suite.
add_test(NAME unit_tests COMMAND tests)