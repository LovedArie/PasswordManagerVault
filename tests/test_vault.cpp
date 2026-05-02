// test_vault.cpp
//
// First TDD cycle for the Vault class.
//
// Story: "As a user, I want to be able to create a new entry, so that I
// can store and access it later."
//
// Smallest possible scenario: an empty Vault has zero entries.
// We start this small on purpose — TDD works best when each step is tiny.

#include "catch.hpp"
#include "Vault.h"
#include "Entry.h"

TEST_CASE("a new Vault has no entires", "[Vault]"){
    Vault vault("test-password");
    vault.unlock("test-password");
    REQUIRE(vault.size() == 0);
}

TEST_CASE("adding an entry to a Vault increases its size", "[Vault]"){
    Vault vault("test-password");
    vault.unlock("test-password");
    Entry entry("github.com", "phan@example.com", "phanp", "hunter2");

    vault.addEntry(entry);

    REQUIRE(vault.size() == 1);
}

TEST_CASE("findBySite returns the matching entry", "[Vault]"){
    Vault vault("test-password");
    vault.unlock("test-password");
    Entry entry("github.com", "phan@example.com", "phanp", "hunter2");
    vault.addEntry(entry);

    auto found = vault.findBySite("github.com");

    REQUIRE(found.has_value());
    REQUIRE(found->site() == "github.com");
    REQUIRE(found->username() == "phanp");
}

TEST_CASE("findBySite returns nothing when no match", "[Vault]"){
    Vault vault("test-password");
    vault.unlock("test-password");

    auto found = vault.findBySite("github.com");

    REQUIRE_FALSE(found.has_value());
}

TEST_CASE("a new Vault starts Locked", "[Vault][lock]"){
    Vault vault("test-password");
    REQUIRE(vault.isLocked());
}

TEST_CASE("unlock with the correct password unlocks the VAULT", "[Vault][lock]"){
    Vault vault("test-password");

    vault.unlock("test-password");

    REQUIRE_FALSE(vault.isLocked());
}

TEST_CASE("addEntry on a locked Vault thorws", "[Vault][lock]"){
    Vault vault("test-password");
    Entry entry("github.com", "a@b.com", "u", "p");

    REQUIRE_THROWS_AS(vault.addEntry(entry), std::runtime_error);

}

TEST_CASE("findBySite on a locked Vault throws", "[Vault][lock]"){
    Vault vault("test-password");

    REQUIRE_THROWS_AS(vault.findBySite("bithub.com"), std::runtime_error);
}