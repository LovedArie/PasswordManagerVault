# 06 - Iteration Plan

## Revision History

| Version | Date | Description | Author |
|---|---|---|---|
| Elaboration iteration 1 | 2026-05-02 | Initial plan for first elaboration iteration. | Phan |

## Introduction

This is the plan for **the next iteration only** — not the whole project.
Per Larman (*Applying UML and Patterns*, Ch. 4 §4.3, Ch. 8 §8.3), the
Iteration Plan is short and focused, ranking work by **risk, coverage, and
criticality**. The riskiest, most architecturally significant items are
attacked first.

This iteration begins the **elaboration phase**. Inception is complete (see
`01_Vision.md`, `02_UseCaseModel.md`, `03_SupplementarySpecification.md`,
`04_Glossary.md`, `05_RiskList.md`).

---

## Iteration E1 — Qt UI MVP

**Date range:** 2026-05-02 → ~2026-05-23 (target: 3 weeks)

### Goal in one sentence

The user can launch the application, create a master password, unlock the
vault, add entries via a form, and search for entries — all through a Qt
graphical interface, with the existing domain layer (`Vault`, `Entry`)
untouched.

### Use cases in scope

| ID | Name | Status this iteration |
|----|------|----------------------|
| UC-01 | Initialize Vault (set master password on first use) | **Partial** — every launch creates a fresh vault since no persistence yet |
| UC-02 | Unlock Vault | **Complete** — implemented via unlock dialog |
| UC-03 | Add Entry | **Complete** — implemented via add-entry form |
| UC-04 | Find Entry by Site | **Complete** — implemented via search box |
| UC-05 | Lock Vault | **Partial** — happens implicitly when app closes |

*Note on UC-01: without file persistence, every app launch is a "first
launch." We show the "create master password" screen every time. This
becomes a one-time flow once persistence arrives, with no UI rework.*

### Other work in scope (technical infrastructure)

- **Install Qt6** (Qt online installer, takes ~1 hour, includes Qt account
  creation)
- **Wire CMake to find and link Qt** (`find_package(Qt6 ...)`,
  `qt_standard_project_setup()`)
- **Learn Qt fundamentals** before integrating: signals/slots, layouts,
  the `QApplication` lifecycle, `QMainWindow` vs `QDialog`
- **Build a Qt-only "Hello World" prototype first** in
  `prototypes/qt-hello/` to validate the install before touching the real
  project (per R-02 mitigation)
- **Add a UI layer** in a new `src/ui/` folder containing the Qt widget
  classes
- **Add a separate UI library target** in CMake so the domain library
  stays Qt-free

### Definition of Done

- All in-scope use cases work end-to-end in the actual graphical
  application.
- Existing **14 assertions / 9 test cases** still pass.
- Domain layer (`Vault`, `Entry`) has **zero code that references any Qt
  type** — Model-View Separation held (Larman, Ch. 13 §13.7).
- The application launches, runs, and closes cleanly with no crashes.
- A manual test checklist (in `docs/`) walks through every use case
  successfully.
- Code committed to git with each meaningful step.

### Estimated duration

**2–3 weeks of evening sessions** (~6–10 sessions of 1–2 hours each).

Honest breakdown:

- Qt install + Hello World prototype: 1 session
- CMake integration with the project: 1 session
- Unlock dialog (smallest widget, learn signal/slot here): 1–2 sessions
- Main window + entries list view: 1–2 sessions
- Add-entry form: 1 session
- Search box wiring: 1 session
- Polish + manual testing + risk re-rank: 1 session

*Larman (Ch. 2) recommends iterations of 2–6 weeks. This fits.*

### Risks attacked this iteration

- **R-02 (Qt learning curve)** — primary risk. Mitigated by the
  prototype-first approach: build a separate "Hello World" Qt project in
  `prototypes/qt-hello/` and verify it compiles/runs on this machine
  before touching the real codebase.
- **R-04 (ADHD focus drift)** — mitigated by ending every session with a
  green build, a git commit, and a one-line "where I left off" note in
  `docs/`.
- **R-05 (C++ memory mistakes)** — moderate increase in exposure since
  Qt has its own object ownership model (parent/child trees, `QObject`
  lifetime). Mitigated by reading Qt's official memory management docs
  *before* writing widget code.
- **R-07 (locked vault is theatre)** — *not made worse* this iteration.
  No persistence means no plaintext file exists yet. Status quo holds.

### Explicitly NOT in scope

- File persistence (deferred to next iteration)
- Real encryption
- Edit Entry / Delete Entry (UC-06, UC-07)
- Visual polish, custom themes, icons, splash screens
- Auto-lock on idle timeout
- Configuration files, command-line arguments
- Installer / packaging

---

## Sources

- Larman, *Applying UML and Patterns* (3rd ed.), Ch. 2 (iteration length),
  Ch. 4 §4.3 (UP artifacts), Ch. 8 §8.3 (risk-driven iteration ranking),
  Ch. 13 §13.7 (Model-View Separation).