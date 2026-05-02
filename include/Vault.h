// Vault.h
//
// The Vault is the top-level container for the user's stored credentials.
// Iteration 1: in-memory only. No persistence, no encryption — those come
// in later iterations.
//
// Stroustrup, *The C++ Programming Language*, Ch. 15 §15.2.2:
// Headers contain DECLARATIONS (telling the compiler what exists).
// Implementations live in .cpp files (the One-Definition Rule, §15.2.3).

#ifndef VAULT_H
#define VAULT_H

#include <cstddef>
#include <vector>
#include <optional>
#include <string>
#include "Entry.h"

class Vault{
    public:
        // Constuct a Vault with its master password.
        // The Vault starts in the locked state.
        explicit Vault(const std::string& masterPassword);
        
        // --- Lock state ---
        bool isLocked() const;

        // Attempt to unlock with a password. If correct, the Vault becomes
        // unlocked. If wrong, it stays locked. (returns nothing - call
        // isLocked() to check the outcome.)
        void unlock(const std:: string& password);

        // --- Operations (require the Vault to be unlocked) ---
        void addEntry(const Entry& entry);
        std::optional<Entry> findBySite(const std::string& siteName) const;
        std::size_t size() const;

    private:
        std::string m_masterPassword;
        bool m_locked;
        std::vector<Entry> m_entries;

        //Helper : thorws std:runtime_error if the Vault is locked.
        // called at the start of every operation that requires unlocking.
        void requireUnlocked() const;
};

#endif