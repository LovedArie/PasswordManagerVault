# Session Notes

A running log of where each session ended. Newest at top.


---

## 2026-05-06 — Qt Hello World prototype works end-to-end

**State:** Iteration E1, R-02 mitigation complete. Qt install validated.

**Done this session:**
- Created `prototypes/qt-hello/` with minimal CMakeLists.txt + main.cpp
- Verified Qt's bundled MinGW (GCC 13.1) is the correct toolchain
- CMake configure clean, build clean, exe runs and shows window
- Learned the gotcha: Qt's bin folder must be on PATH at runtime (will use windeployqt for real app later)

**Where to pick up next:**
1. Wire Qt into the *main* project's CMakeLists.txt (the real one at the root)
2. Decide whether the main project switches to Qt's MinGW or finds another way to coexist with MSYS2's GCC 15.2
3. Once main project builds with Qt linked (no UI yet, just linkage), start the unlock dialog

**Open question for next session:**
- Compiler ABI question: can the existing tests (built with MSYS2 GCC 15.2) and Qt code (needs GCC 13.1) live in one CMake project? Or do we standardize on GCC 13.1 for everything? Will research before next session.


---

## 2026-05-03 — End of inception, Qt installed

**State:** Iteration E1 (Qt UI MVP) — kickoff phase. Domain layer complete and tested.

**Done this session:**
- All 5 inception artifacts written and saved (`docs/01–05`)
- Iteration plan E1 written (`docs/06`)
- Qt 6.11.0 installed at `C:\Qt\6.11.0\mingw_64\` with bundled MinGW 13.1 at `C:\Qt\Tools\mingw1310_64\`
- Qt Creator 19.0.1 installed at `C:\Qt\Tools\QtCreator\`
- Domain layer: `Vault` and `Entry` complete, 14 assertions / 9 test cases passing

**Where to pick up next:**
1. Build a "Hello World" Qt prototype in `prototypes/qt-hello/` (separate
   tiny CMake project, isolated from main code) — per R-02 mitigation
2. Once Hello World runs, wire Qt into the main project's CMake
3. Then start UI cycles: unlock dialog first

**Critical things to remember:**
- The main project uses **MSYS2's MinGW (GCC 15.2)** for the existing tests
- Qt was built against **its own bundled MinGW (GCC 13.1)** — different compiler
- When we link the main project against Qt, we must switch to Qt's MinGW
- Domain layer (`Vault`, `Entry`) must stay Qt-free per Larman's Model-View Separation (Ch. 13 §13.7)

**Open questions / decisions deferred:**
- Will edit/delete entries (UC-06, UC-07) come in this iteration? Currently scoped out, may revisit
- File persistence: deferred to iteration E2

**Risks to re-rank at start of next session:**
- R-02 (Qt learning curve) — about to be tested in earnest
- R-04 (focus drift) — first real test of the session-notes protocol

