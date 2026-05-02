# 04 — Glossary

> **What this is**: A list of noteworthy terms used in this project, with
> their definitions. Per Larman (*Applying UML and Patterns*, Ch. 7 §7.8–7.9),
> this also doubles as a **data dictionary** later — recording metadata about
> the data (formats, validation rules, allowed values).
>
> **When to start**: Day one. Larman is explicit: "Start the Glossary early.
> It will quickly become a useful repository of detailed information related
> to fine-grained elements."
>
> **Why it matters**: Different stakeholders use the same term to mean
> slightly different things. The Glossary forces an agreed definition,
> reducing miscommunication and ambiguous requirements.

---
# Glossary

## Revision History

| Version | Date | Description | Author |
|---|---|---|---|
| Inception draft | 2026-05-02 | First draft. To be refined during elaboration. | Phan |
| Inception draft | 2026-05-02 | First draft. To be refined during elaboration. | Phan |

## Definitions

| Term | Definition |
|---|---|
| **Vault** | The top-level container holding the user's stored entries. A Vault is protected by a master password and is either *locked* or *unlocked*. Operations (add, find, etc.) require the Vault to be unlocked. |
| **Entry** | One stored login record. Holds four fields: site, email, username, password. *Note: we deliberately use "Entry" rather than "Credential" to avoid conflict with the master credential used to unlock the Vault.* |
| **Master Password** | The single password that unlocks the user's Vault. The user must remember this — if forgotten, all stored entries become permanently inaccessible. |
| **Locked / Unlocked Vault** | A Vault's two states. A new Vault always starts locked. `unlock(password)` transitions it to unlocked if the password matches. In iteration 1 this is a logical flag; in a later iteration the locked state will correspond to encrypted-on-disk storage. |
| **Site** | The platform or service an entry is for (e.g. "github.com", "Netflix"). One of the four fields of an Entry. |
| **Search** | The act of looking up an entry inside the Vault, currently by site name. Returns either the matching entry or nothing. |
| **Iteration 1** | The first version of this software. Scope: a single user, local-only Vault with master-password lock, in-memory storage, no encryption, no UI. Future iterations add persistence, encryption, the Qt GUI, and possibly multi-user support. |
| **Domain Layer / Domain Logic** | The core business classes (`Vault`, `Entry`) that model the password-manager problem. Independent of any UI or storage technology. Per Larman §17, the domain layer must not know about the UI. |
| **TDD (Test-Driven Development)** | The development practice we use: write a failing test first, then write the minimum code to make it pass, then refactor. Each loop is called a "cycle." |
| **Out of scope (iteration 1)** | Cross-platform mobile support, cloud sync, real cryptographic encryption, multi-user support, error journal/handler, GUI. All deferred to future iterations. |

## Sources

- Larman, *Applying UML and Patterns* (3rd ed.), Ch. 7 §7.8–7.9 (Glossary)
- Stroustrup, *The C++ Programming Language*, Ch. 15 (information hiding, source structure)
