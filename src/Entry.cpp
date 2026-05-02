// Entry.cpp
//
// Implementation of the Entry class. Pure data holder for now.

#include "Entry.h"

Entry::Entry(
    const std::string& site,
    const std::string& email,
    const std::string& username,
    const std::string& password)
    : m_site(site),
      m_email(email),
      m_username(username),
      m_password(password)
      {

      }

const std::string& Entry::site() const {return m_site;}
const std::string& Entry::email() const {return m_email;}
const std::string& Entry::username() const {return m_username;}
const std::string& Entry::password() const {return m_password;}