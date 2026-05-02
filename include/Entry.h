// Entry.h
//
// An Entry is one stored login record: site, email, username, password.
// Iteration 1: plain strings, no encryption (encryption comes later).

#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry{
    public:
        Entry(
            const std::string& site,
            const std::string& email,
            const std::string& username,
            const std::string& password
        );

        const std::string& site() const;
        const std::string& email() const;
        const std::string& username() const;
        const std::string& password() const;

    private:
        std::string m_site;
        std::string m_email;
        std::string m_username;
        std::string m_password;
};

#endif