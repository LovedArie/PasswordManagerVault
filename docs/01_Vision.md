# 01 — Vision

> **What this is**: A short executive summary of the project. Per Larman
> (*Applying UML and Patterns*, Ch. 4 §4.3, Table 4.1), the Vision describes
> the high-level goals, constraints, and business case. It's the document
> someone reads in 3 minutes to understand "what is this project and why."
>
> **When to write it**: First. Even a rough first draft of the Vision should
> exist before anything else (Larman, Ch. 7 — "Should You Write the Vision or
> Use Cases First?"). Refine it during elaboration.
>
> **Length**: 1-2 pages max during inception. Anything longer means you're
> doing too much detail too early.

---

# Vision

## Revision History

| Version | Date | Description | Author |
|---|---|---|---|
| Inception draft | 2026-05-02 | First draft. To be refined during elaboration. | Phan |

## Introduction

We envision a personal, locally-stored password manager for individuals who
want to keep their own credentials on their own machine — without trusting a
third-party cloud service. The application provides a graphical desktop
interface for storing and retrieving login entries, protected by a single
master password.

## Positioning

### Problem Statement

Modern users have dozens or hundreds of online accounts, each requiring a
different strong password. Remembering them all is impossible, reusing one
password is dangerous, and trusting a third-party cloud service requires
giving someone else access to all your secrets.

### Product Position Statement

This is a single-user, local-only password manager. Unlike cloud-based
competitors (1Password, Bitwarden, LastPass), nothing is uploaded anywhere
— the user's data lives on their own machine. Unlike command-line tools
(`pass`, KeePassXC's CLI), it provides an accessible graphical interface.
The trade-off is explicit: the user gives up cross-device sync in exchange
for full control over their data.

## Users

A single individual using their own personal computer to store and retrieve
their own login information. Iteration 1 supports one user per installation;
multi-user support is deferred to a future iteration.

## Summary of System Features

Per Larman (Ch. 7 §7.7), system features are externally observable services
the system provides. They pass the linguistic test: *"The system does
&lt;feature X&gt;."*

**Iteration 1 (in progress):**

- The system stores login entries (site, email, username, password)
- The system retrieves an entry by site name
- The system protects access with a master password
- The system provides a graphical user interface (Qt)

**Future iterations:**

- The system persists entries between sessions (file storage)
- The system encrypts stored data at rest

For non-functional requirements (UI framework choice, security properties,
platform support), see `03_SupplementarySpecification.md`.

## Success Criteria

The user can: install the application, set a master password, add several
entries, close the application, reopen it, unlock with the master password,
and retrieve their entries — all through a desktop GUI, without command-line
interaction.

*Note: this success criterion spans iterations 1 and 2, since it implicitly
requires file persistence (delivered in iteration 2).*

## Out of Scope

The following are deliberately excluded to keep the project achievable:

- Mobile platforms (iOS, Android)
- Cloud sync / multi-device access
- Multi-user support on a single installation
- Browser autofill / browser extension integration
- Password generation (entries are user-supplied)
- Two-factor / TOTP code storage
- Sharing entries with other users

These exclusions may be revisited after iteration 1 is complete, but only
if doing so does not delay the core deliverable.

## Constraints

- **Language:** C++17 (per project template; chosen for learning value and Qt compatibility)
- **GUI framework:** Qt
- **Build system:** CMake
- **Testing:** Catch2 v2 (header-only)
- **Platform:** Desktop (Windows, with Linux/macOS feasible later via Qt's portability)
- **Personal project:** No hard deadline, no budget, learning-driven

## Sources

- Larman, *Applying UML and Patterns* (3rd ed.), Ch. 4 §4.3 (inception artifacts), Ch. 7 §7.6–7.7 (Vision structure and system features)
