// Vault.cpp
//
// Implementation of the Vault class. We write JUST ENOUGH code to make
// the failing test pass — nothing more. This is a core TDD discipline:
// don't add features the tests don't require yet. (Beck, "Test Driven
// Development: By Example".)

#include "Vault.h"
#include <stdexcept>

Vault::Vault(const std::string& masterPassword)
: m_masterPassword(masterPassword),
  m_locked(true)
{
    // m_size starts at zero - an empty vault has no entries
}

bool Vault::isLocked() const{
    return m_locked;
}

void Vault::unlock(const std::string& password){
    if(password == m_masterPassword) {
        m_locked = false;
    }
    // If the pssword is wrong, m_locked stays true. No exception:
    // a wrong password is normal user behavior, not a programmer errr.
}

void Vault::addEntry(const Entry& entry){
    requireUnlocked();
    m_entries.push_back(entry);
}

std::size_t Vault::size() const{
    return m_entries.size();
}

std::optional<Entry> Vault::findBySite(const std::string& siteName) const{
    requireUnlocked();
    for (const Entry& entry: m_entries){
        if(entry.site() == siteName) {
            return entry;
        }
    }
    return std::nullopt;
}

void Vault::requireUnlocked() const{
    if(m_locked){
        throw std::runtime_error("Vault is locked");
    }
}