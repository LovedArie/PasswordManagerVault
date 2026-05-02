# How This Template Works

> Delete this file when you copy the template into a real project. It exists
> only to teach you how to use the template.

## The core idea

Larman's *Applying UML and Patterns* (Ch. 2 §2.12) compares UP artifacts to
medicines in a pharmacy: you don't take all of them, you pick the ones that
match the ailment. **Same with this template.** It includes stubs for many
artifacts so you don't have to remember them, but you only fill in the ones
that add value to *this particular* project.

## How to start a new project

```bash
# Copy the template to a new folder
cp -r project-template/ my-new-project/
cd my-new-project/

# Make it a fresh git repo
rm -rf .git
git init

# Delete this guide — you don't need it in your real project
rm HOW_THIS_TEMPLATE_WORKS.md

# Rewrite README.md to be about YOUR project, not the template

# Start filling in docs/01_Vision.md first. Just a few sentences.
```

## Inception phase: what to fill in first

According to Larman (Ch. 4 §4.4 — "You Know You Didn't Understand Inception
When..."), the inception phase is **short** (a few weeks max) and is **not**
the requirements phase. Its job is just to decide whether the project is worth
serious investigation.

So during inception, only the following stubs need *brief, incomplete* content:

1. **`docs/01_Vision.md`** — a short paragraph: what is this, why does it exist?
2. **`docs/02_UseCaseModel.md`** — list of actor and use case *names* (not full
   detail). Maybe 1-2 use cases written out as examples.
3. **`docs/03_SupplementarySpecification.md`** — the few non-functional
   requirements that will shape the architecture (e.g. "must run offline").
4. **`docs/04_Glossary.md`** — start it on day one. Add terms as they come up.
5. **`docs/05_RiskList.md`** — what could go wrong? Fill in 3-5 risks.

Leave the others empty until you actually need them. Larman is explicit
(Ch. 4 §4.3): artifacts should not be created unless they will add real
practical value.

## Inception phase: things you should NOT do yet

From Larman, Ch. 4 §4.4, these are signs you've misunderstood inception:

- Trying to define most of the requirements
- Trying to make estimates that are reliable
- Defining the architecture in detail
- Believing the sequence is: 1) define requirements, 2) design architecture,
  3) implement. (That's waterfall thinking, not iterative.)

Most requirements analysis happens in **elaboration**, the phase after
inception, in parallel with early production-quality programming and testing.

## What about the code side?

Stroustrup, Ch. 15 §15.3.1, recommends starting any "simple program for my own
use" with a **single-header** organization: one `.h` file declares everything
shared, plus several `.cpp` files for the implementations. He notes you can
always reorganize into multiple headers later if the program grows.

That means at the start of a new project:

- Write your code in `src/main.cpp`.
- When something needs to be shared between files, declare it in a header
  inside `include/`, define it in a `.cpp` inside `src/`.
- Headers contain *declarations* (Stroustrup §15.2.2). Source files contain
  *definitions* (§15.2.3 — the One-Definition Rule).

## Sources

- Larman, *Applying UML and Patterns* (3rd ed.), Ch. 2 §2.12; Ch. 4 §4.1–4.4
- Stroustrup, *The C++ Programming Language*, Ch. 15 §15.2.2, §15.2.3, §15.3.1
