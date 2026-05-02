# 05 - Risk List

## Revision History

| Version | Date | Description | Author |
|---|---|---|---|
| Inception draft | 2026-05-02 | First draft. To be re-ranked every iteration. | Phan |

## Introduction

This is a running list of project risks with mitigation plans. Per Larman
(*Applying UML and Patterns*, Ch. 4 §4.3, Table 4.1), risks fall into four
categories: business, technical, resource, and schedule.

In the Unified Process, work is **risk-driven** — early iterations are
organized to attack the riskiest, most architecturally significant items
first (Larman, Ch. 8 §8.3).

**This list must be re-ranked at the start of every iteration.** New risks
appear; old risks get retired as their causes are mitigated or proven
inapplicable.

**Likelihood / Impact scale**: H = High, M = Medium, L = Low.

## Risks

### R-01 — Cryptography mistakes

| Field | Value |
|---|---|
| Type | Technical |
| Likelihood | H |
| Impact | H |

**Description:** Implementing real encryption (future iteration) is
notoriously easy to get subtly wrong. Bad key derivation, predictable IVs,
side-channel leaks, or storing keys in plaintext can all silently break the
security guarantee. A "secure" password manager that isn't actually secure
is *worse* than no password manager — false confidence.

**Mitigation:** Use a vetted library (libsodium) rather than rolling our
own crypto. Build a small prototype in `prototypes/` before integrating.
Read the OWASP password storage cheat sheet and libsodium's documentation
in full before writing the first line of crypto code.

### R-02 — Qt learning curve

| Field | Value |
|---|---|
| Type | Technical / Schedule |
| Likelihood | H |
| Impact | M |

**Description:** Qt has its own meta-object system, build conventions
(`moc`, `qrc`), and signal/slot mechanism unlike anything in standard C++
or Java. Learning it well takes weeks, and tutorials often skip subtle
deployment issues (DLLs on Windows, signal threading).

**Mitigation:** Allocate dedicated time for Qt-only learning before
integrating with the domain code. Build a "Hello World" Qt window first,
then a separate Qt prototype that calls into a stub Vault, *before*
connecting Qt to the real Vault. Lean on Qt's official tutorials, not
random YouTube videos.

### R-03 — Scope creep / "just one more feature"

| Field | Value |
|---|---|
| Type | Schedule / Business |
| Likelihood | H |
| Impact | H |

**Description:** This is a personal learning project with no deadline,
which is the textbook recipe for endless scope expansion. Every feature
parked in `01_Vision.md` (cloud, mobile, password generation, 2FA, browser
extension, sharing) will tempt scope-back-in. Without external pressure,
projects like this often stall halfway through iteration 2.

**Mitigation:** Treat each iteration as a contract. Don't start iteration
N+1 until iteration N is fully green and committed to git. Re-read this
risk at the start of every session. Keep the "Out of Scope" section of the
Vision visible.

### R-04 — ADHD focus drift across long-running sessions

| Field | Value |
|---|---|
| Type | Resource |
| Likelihood | H |
| Impact | M |

**Description:** Long C++ sessions with deep concentration are taxing.
Risk: building momentum mid-cycle, getting interrupted, returning days
later having lost the mental model of where things stood, and starting
from "where was I?" rather than from a known checkpoint.

**Mitigation:** End every session at a green state (all tests passing).
Commit to git before stopping. Keep a one-paragraph "where I left off"
note in `docs/` updated after each session. Embrace TDD's small cycles —
they create natural break points.

### R-05 — Memory mistakes / undefined behavior in C++

| Field | Value |
|---|---|
| Type | Technical |
| Likelihood | M |
| Impact | M |

**Description:** Coming from Java (garbage-collected, no manual memory
management, no undefined behavior), C++ exposes whole categories of bugs
Java protects against: dangling references, uninitialized variables,
integer overflow, iterator invalidation, undefined behavior. Some bugs
*appear to work* and break later.

**Mitigation:** Stick to modern C++ idioms (`std::vector`, `std::optional`,
`std::string`, no raw `new`/`delete`). Enable compiler warnings
aggressively (`-Wall -Wextra -Wpedantic`). Run AddressSanitizer
(`-fsanitize=address`) on the test executable when builds get strange.
When in doubt, ask.

### R-06 — File persistence trickier than expected

| Field | Value |
|---|---|
| Type | Technical |
| Likelihood | M |
| Impact | H |

**Description:** Reading and writing files in C++ involves choices (text
vs binary, encoding, line endings, atomic writes). A file half-written
during a crash can corrupt the entire vault. Data loss is catastrophic for
a password manager.

**Mitigation:** Use the "write to temp, fsync, atomic rename" pattern when
implementing save. Test save/load on real files in a test fixture.
Consider a checksum or HMAC over the file contents to detect corruption.
Defer until iteration 2; don't try to do it during iteration 1.

### R-07 — "Locked" vault is theatre during iteration 1

| Field | Value |
|---|---|
| Type | Business / Technical |
| Likelihood | L |
| Impact | H |

**Description:** During iteration 1, the lock state is a boolean flag.
The data is in plaintext memory and (later) in plaintext files. Anyone
reading process memory or saved files sees everything. If anyone
mistakenly believes iteration 1 is *secure* and uses it for real
passwords, the consequences are bad.

**Mitigation:** Do not distribute or share iteration 1 binaries. Document
the limitation prominently in the README. Do not personally use it for
real credentials until file-level encryption ships in a later iteration.

## Sources

- Larman, *Applying UML and Patterns* (3rd ed.), Ch. 4 §4.3 (Table 4.1
  inception artifacts); Ch. 8 §8.3 (risk-driven iteration ranking).