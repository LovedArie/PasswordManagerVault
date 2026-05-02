# 02_Use-Case Model

## Revision History

| Version | Date | Description | Author |
|---|---|---|---|
| Inception draft | 2026-05-02 | First draft. To be refined during elaboration. | Phan |

## Introduction

This document captures the functional requirements of the password manager
as a set of use cases — typical scenarios of using the system, written from
the user's perspective. Per Larman (*Applying UML and Patterns*, Ch. 4 §4.3),
during inception only 10–20% of use cases are written in detail; the rest are
named placeholders to be elaborated in subsequent iterations.

## Actors

An *actor* is anyone (or any external system) that interacts with the
system. Actors are roles, not specific people.

| Actor | Description |
|---|---|
| **User** | A single individual using the application on their personal computer to manage their own login entries. Initiates all use cases in iteration 1. |

*Note: iteration 1 has no external system actors (no cloud service, no
network integrations, no third-party authentication). External actors may
appear in future iterations.*

## Use Cases — by Name

| ID | Name | Primary actor | Detailed? |
|----|------|---------------|-----------|
| UC-01 | Initialize Vault (set master password on first use) | User | |
| UC-02 | Unlock Vault | User | ⭐ |
| UC-03 | Add Entry | User | |
| UC-04 | Find Entry by Site | User | |
| UC-05 | Lock Vault (manual lock or auto-lock on close) | User | |
| UC-06 | Edit Entry *(future)* | User | |
| UC-07 | Delete Entry *(future)* | User | |
| UC-08 | Save Vault to Disk *(future iteration)* | User | |
| UC-09 | Load Vault from Disk *(future iteration)* | User | |

⭐ = fully dressed in this document. Others remain named placeholders during
inception, to be elaborated as their corresponding code is built.

## Detailed Use Case (Fully Dressed)

### UC-02: Unlock Vault

**Primary actor**: User

**Stakeholders and interests**:
- *User*: wants quick access to their entries when entering the correct
  password; wants to be protected against someone else getting access by
  guessing.

**Preconditions**:
- The Vault has been previously initialized (a master password is set).
- The Vault is currently in the locked state.

**Success guarantee (postconditions)**:
- The Vault is in the unlocked state.
- The User can perform operations (add, find, etc.) on the Vault.

**Main success scenario** (the "happy path"):

1. User opens the application.
2. System displays the unlock prompt.
3. User enters the master password.
4. System verifies the password matches the stored master password.
5. System transitions the Vault to the unlocked state.
6. System displays the entries view.

**Extensions** (alternate flows):

- **3a. User enters an incorrect password:**
    1. System leaves the Vault locked.
    2. System displays a generic "incorrect password" message *(deliberately
       generic — does not reveal whether the password is close or how many
       attempts have occurred, to limit information given to potential
       attackers).*
    3. User retries from step 3, or cancels.
- **3b. User cancels the prompt:**
    1. System closes (or returns to a locked-state idle view).

**Special requirements**:
- The password input field must mask characters (display dots, not the
  actual text).
- The system must not log or display the entered password anywhere.
- *(Future)* Consider rate-limiting or backoff after repeated failed
  attempts.

**Frequency of occurrence**: Once per session (when the user opens the app).

## Notes for Future Iterations

- **No "forgot password" flow exists by design.** If the User forgets the
  master password, the Vault contents become permanently inaccessible. This
  is a deliberate trade-off: it preserves the security guarantee that no
  one (including the application maintainer) can decrypt the Vault without
  the master password. To be documented in user-facing materials when
  available.
- **Lockout after N failed attempts** is *not* planned. Industry practice
  for local password managers leans toward attempt-slowing (rate-limiting)
  rather than hard lockout, since hard lockout creates a denial-of-service
  attack on the legitimate user.

## Sources

- Larman, *Applying UML and Patterns* (3rd ed.), Ch. 4 §4.3 (inception
  artifacts), Ch. 5–6 (use case format and authoring), Ch. 7 §7.4
  (Supplementary Specification cross-reference).
