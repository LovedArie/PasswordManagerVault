# Password Manager

A personal, locally-stored password manager with a single master-password
lock and a Qt desktop GUI. Single-user, offline, no cloud sync. Built in
C++17 as a software-engineering learning project following Craig Larman's
Unified Process.

---

## ⚠️ DO NOT USE FOR REAL CREDENTIALS

This project is mid-development. As of the current iteration:

- Stored data is held in **plaintext in memory**.
- In the next iteration, it will be written to disk **also in plaintext**.
- The "locked" state is a boolean flag — **not real encryption**.

Anyone with read access to this process's memory or its saved files will see
every stored entry in clear text.

Real cryptographic encryption is planned for a future iteration. Until that
ships, treat this as a learning prototype only — **do not store real
passwords in it**.

See `docs/05_RiskList.md` (R-07) for the full analysis.

---

## What this is

A desktop password manager that:

- Stores login entries (site, email, username, password) for one user
- Unlocks via a single master password
- Provides a graphical interface (Qt) — no command line needed
- Lives entirely on the local machine; nothing is uploaded anywhere

**Deliberately out of scope** (per `docs/01_Vision.md`): cloud sync, mobile,
multi-user, password generation, 2FA / TOTP, browser autofill, sharing.

For the full goals and rationale, see `docs/01_Vision.md`.

## Current status

**Phase:** Elaboration, iteration E1 (Qt UI MVP).
**Latest checkpoint:** see `SESSION_NOTES.md`.

### What works

- ✅ Domain layer: `Vault` and `Entry` classes — 14 assertions / 9 test cases passing (Catch2)
- ✅ Master-password unlock logic (in-memory)
- ✅ Add entry / find entry by site
- ✅ Four Qt prototypes proving every mechanic needed for the UI:
  - `qt-hello/` — Qt install validated
  - `qt-signals/` — signals/slots with lambdas
  - `qt-form/` — masked password input, layouts, reading widget text
  - `qt-dialog/` — modal `QDialog::exec()` with accept/reject

### In progress

- 🚧 Resolve the compiler-ABI question (MSYS2 GCC 15.2 vs Qt's bundled GCC 13.1)
- 🚧 Wire Qt into the root `CMakeLists.txt`
- 🚧 Build the real unlock dialog using the proven prototype mechanics

### Deferred to later iterations

- File persistence (target: iteration E2)
- Real cryptographic encryption (target: iteration E3+; planned library: libsodium with Argon2 KDF)
- Edit / Delete entries (UC-06, UC-07)
- Auto-lock on idle, installer, multi-platform builds

---

## Tech stack

| Component | Choice |
|---|---|
| Language | C++17 |
| GUI framework | Qt 6.11.0 |
| Compiler | MinGW GCC 13.1 (Qt's bundled toolchain) |
| Build system | CMake 3.20+ |
| Test framework | Catch2 v2 (header-only, in `include/catch.hpp`) |
| Platform | Windows (Linux/macOS feasible via Qt's portability) |

Choice rationale lives in `docs/03_SupplementarySpecification.md` (Implementation Constraints).

---

## Building and running

### One-time per shell: set up the Qt environment

From the project root, in PowerShell:

```powershell
. .\scripts\qt-env.ps1
```

The leading `. ` (dot-space) is **dot-sourcing** — it runs the script in the
current shell so the PATH changes persist. Without it, the changes vanish
when the script returns.

You should see `Qt environment configured (GCC 13.1.0, Qt 6.11.0)`.

### Build the project

```powershell
cmake -G "MinGW Makefiles" -B build -DCMAKE_PREFIX_PATH="C:/Qt/6.11.0/mingw_64"
cmake --build build
```

### Run the tests

```powershell
.\build\tests\<test-executable-name>.exe
```

*(Adjust the path / name to match your actual `CMakeLists.txt` target. Tests
use Catch2 v2 and currently report 14 assertions across 9 cases.)*

### Run a Qt prototype (sanity check)

```powershell
cd prototypes\qt-dialog
cmake -G "MinGW Makefiles" -B build -DCMAKE_PREFIX_PATH="C:/Qt/6.11.0/mingw_64"
cmake --build build
.\build\qt-dialog.exe
```

---

## Project layout

```
password-manager/
├── README.md                 ← this file
├── CMakeLists.txt            ← root build script
├── SESSION_NOTES.md          ← running log of each work session
│
├── scripts/
│   └── qt-env.ps1            ← PATH setup for Qt sessions (dot-source it)
│
├── docs/                     ← Unified Process artifacts (Larman)
│   ├── 01_Vision.md
│   ├── 02_UseCaseModel.md
│   ├── 03_SupplementarySpecification.md
│   ├── 04_Glossary.md
│   ├── 05_RiskList.md        ← read R-07 before using
│   ├── 06_IterationPlan.md
│   ├── 07_PhasePlan.md
│   └── 08_DevelopmentCase.md
│
├── src/                      ← .cpp files (domain logic — Vault, Entry)
├── include/                  ← .h / .hpp files (declarations)
├── tests/                    ← Catch2 unit tests
├── diagrams/                 ← .puml files (PlantUML)
├── prototypes/               ← Qt learning prototypes (R-02 mitigation)
│   ├── qt-hello/
│   ├── qt-signals/
│   ├── qt-form/
│   └── qt-dialog/
└── build/                    ← compiler output (git-ignored)
```

The domain layer (`src/`, `include/`) deliberately contains **zero Qt
dependencies**, per Larman's Model-View Separation Principle
(Ch. 13 §13.7). The UI layer will live in its own `src/ui/` folder once
integrated.

---

## Where to read more

| Document | Purpose |
|---|---|
| `docs/01_Vision.md` | High-level goals and constraints (the 3-minute overview) |
| `docs/02_UseCaseModel.md` | Functional requirements as use cases (UC-01 … UC-09) |
| `docs/03_SupplementarySpecification.md` | Non-functional requirements (FURPS+) |
| `docs/04_Glossary.md` | Domain terms — Vault, Entry, Master Password, etc. |
| `docs/05_RiskList.md` | Project risks and mitigations (read R-07!) |
| `docs/06_IterationPlan.md` | What this iteration aims to deliver |
| `docs/08_DevelopmentCase.md` | Which UP artifacts this project uses, and why |
| `SESSION_NOTES.md` | Running log of where each session ended |

---

## License & dependencies

Personal learning project. Not for distribution.

| Dependency | License | Used as |
|---|---|---|
| Qt 6.11.0 | LGPL v3 | Dynamic linking (acceptable per LGPL) |
| Catch2 v2 | BSL-1.0 | Header-only inclusion |

---

## Sources behind this project's structure

- **Larman, *Applying UML and Patterns* (3rd ed.)** — Unified Process; inception
  and elaboration artifacts (Ch. 4 §4.3); use case authoring (Ch. 5–6);
  risk-driven iteration planning (Ch. 8 §8.3); Model-View Separation
  (Ch. 13 §13.7).
- **Stroustrup, *The C++ Programming Language* (4th ed.)** — C++17 language
  reference; separate compilation, headers vs. sources, One-Definition Rule
  (Ch. 15); lambdas and capture lifetime (Ch. 11.4); object ownership and
  destruction (Ch. 16).