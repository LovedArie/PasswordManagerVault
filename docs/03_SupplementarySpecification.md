# Supplementary Specification

## Revision History

| Version | Date | Description | Author |
|---|---|---|---|
| Inception draft | 2026-05-02 | First draft. To be refined during elaboration. | Phan |

## Introduction

This document captures requirements that are not expressed in the use cases
— mostly non-functional requirements such as security, performance, and
implementation constraints. Per Larman (Ch. 4 §4.3), during inception only
the most influential non-functional requirements are identified, since
some have major impact on architectural choices.

Organized by the **FURPS+** model: Functionality, Usability, Reliability,
Performance, Supportability, plus implementation/interface/packaging/legal
constraints.

## Functionality (Cross-Cutting)

**Security:**
- All access to the Vault requires the master password. The Vault refuses
  operations (add, find, etc.) when locked.
- The master password is never displayed or logged.
- *(Future iteration)* Stored data must be encrypted at rest using a key
  derived from the master password. Algorithm: TBD — likely libsodium with
  Argon2 KDF.

**Logging *(future iteration)*:**
- An error journal will record failed unlock attempts and other anomalies,
  separate from any data the user can read.

## Usability

- The UI must be a graphical desktop interface (Qt). Command-line
  interaction is not acceptable as the primary interface.
- Password fields must mask input (dots, not plaintext).
- The interface should be operable by a single user without training — no
  manual or onboarding flow required for basic operations (unlock, add,
  find).
- **Accessibility**: Standard Qt accessibility (keyboard navigation,
  screen-reader hooks via Qt's built-in support) — no special accessibility
  work planned for iteration 1.

## Reliability

- The application must not crash or lose data on incorrect password entry,
  application close, or system shutdown.
- *(Future iteration)* If the persistence file is corrupted or partially
  written, the application must detect the corruption rather than silently
  load garbage data.
- Iteration 1 has no availability/uptime requirements (no server component).

## Performance

- Unlock and entry retrieval must feel instant to the user (under 100ms
  for a vault of fewer than 1000 entries).
- No specific performance budget for vaults larger than 1000 entries — to
  be revisited if it becomes relevant.
- Startup time should be reasonable for a desktop application (under ~2
  seconds on modern hardware), but not formally measured during iteration 1.

## Supportability

- Code must be testable: domain logic (`Vault`, `Entry`) must be
  exercisable through unit tests without requiring a running UI. *(Already
  enforced by the iteration 1 architecture — the domain layer is
  independent of Qt.)*
- Single-language project (C++17). No localization in iteration 1;
  English-only UI strings.
- Configuration is hardcoded at compile time. No config files until
  justified by need.

## "+" — Additional Constraints

### Implementation Constraints

- **Language:** C++17 (per project template; aligned with Stroustrup's
  coverage in *The C++ Programming Language*)
- **Compiler:** GCC 15.2 (MinGW-w64 / UCRT64 on Windows)
- **Build system:** CMake 3.20+
- **Test framework:** Catch2 v2 (single-header, in `include/catch.hpp`)
- **GUI framework:** Qt (specific version: Qt6, to be confirmed at install time)

### Interface Constraints

- No network access in iteration 1. The application must function entirely
  offline.
- No integration with external services or APIs in iteration 1.

### Packaging

- Single-machine desktop install. No installer requirements specified yet.

### Legal / Licensing

- Personal project; no commercial licensing concerns. Dependencies must be
  compatible with personal/non-commercial use:
    - **Catch2 v2**: BSL-1.0 ✓
    - **Qt**: LGPL v3 (acceptable for dynamic linking) ✓

## Sources

- Larman, *Applying UML and Patterns* (3rd ed.), Ch. 4 §4.3 (inception
  artifacts), Ch. 5 §5.5, Ch. 7 §7.4 (Supplementary Specification example
  and structure).
- Stroustrup, *The C++ Programming Language*, Ch. 15 (rationale for
  C++17 minimum).