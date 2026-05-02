// test_entry.cpp
//
// Story: an Entry holds the four fields of a stored login record:
// site, email, username, password.

#include "catch.hpp"
#include "Entry.h"

TEST_CASE("an Entry holds its four fields", "[Entry]"){
    Entry entry("github.com", "phan@example.com", "phanp", "hunter2");

    REQUIRE(entry.site() == "github.com");
    REQUIRE(entry.email() == "phan@example.com");
    REQUIRE(entry.username() == "phanp");
    REQUIRE(entry.password() == "hunter2");
}