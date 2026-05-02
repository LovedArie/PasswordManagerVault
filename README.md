# Project Template

A reusable starting point for new C++ projects, organized around the Unified
Process (UP) artifacts described in Craig Larman's *Applying UML and Patterns*
(3rd ed.) and the C++ source-file conventions described in Bjarne Stroustrup's
*The C++ Programming Language* (Ch. 15).

> Read `HOW_THIS_TEMPLATE_WORKS.md` first. It explains the philosophy and how
> to start a new project from this template.

---

## Folder layout

```
project-template/
├── README.md                    ← project overview (THIS FILE — replace per project)
├── HOW_THIS_TEMPLATE_WORKS.md   ← keep this in the template, delete it in real projects
├── .gitignore                   ← what git should ignore
├── CMakeLists.txt               ← build script
│
├── docs/                        ← UP / Larman process artifacts
│   ├── 01_Vision.md
│   ├── 02_UseCaseModel.md
│   ├── 03_SupplementarySpecification.md
│   ├── 04_Glossary.md
│   ├── 05_RiskList.md
│   ├── 06_IterationPlan.md
│   ├── 07_PhasePlan.md
│   └── 08_DevelopmentCase.md
│
├── src/                         ← .cpp files (definitions)
│   └── main.cpp
├── include/                     ← .h / .hpp files (declarations only)
├── tests/                       ← unit tests
├── diagrams/                    ← .puml files (PlantUML)
├── prototypes/                  ← throwaway proof-of-concept code
└── build/                       ← compiler output (git-ignored, created by CMake)
```

## Replace this README per project

When you copy this template for a real project, REWRITE this README to be about
that project. A good README answers:

- **What is this project?** (1-2 sentences)
- **How do I build it?** (exact commands)
- **How do I run it?** (exact commands)
- **How do I run the tests?**
- **License**

Keep it short — readers skim.

## Build (placeholder commands)

```bash
mkdir build && cd build
cmake ..
cmake --build .
./project-name
```

## Sources behind this structure

- Larman, *Applying UML and Patterns* (3rd ed.), Ch. 4 §4.3 (Table 4.1: inception artifacts)
- Stroustrup, *The C++ Programming Language*, Ch. 15 (separate compilation,
  headers vs. sources, One-Definition Rule)


## Getting going
