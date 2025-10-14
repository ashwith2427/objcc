# 🧩 objcc

**objcc** is a modern **C++ / Objective-C bridge** powered by the **Curiously Recurring Template Pattern (CRTP)** and the **PIMPL idiom**.
It enables seamless communication between C++ and Objective-C runtime APIs (`objc_msgSend`, `objc_getClass`, etc.) — without `.mm` wrappers or manual boilerplate.

---

## 🚀 Overview

`objcc` provides a **type-safe**, **header-only**, and **lightweight** interface to send Objective-C messages directly from C++.
It abstracts away the low-level runtime calls while preserving C++’s type system and compile-time dispatch capabilities.

Architecturally, it combines:
- 🧱 **CRTP** — to bind implementation behavior at compile time
- 🔒 **PIMPL** — to encapsulate Objective-C runtime details behind clean interfaces

---

## 🧠 Design Philosophy

`objcc` is designed with these goals in mind:

1. **Type Safety** — Message calls are specialized at compile time based on return type
2. **Encapsulation** — Objective-C runtime objects and selectors are hidden behind a PIMPL layer
3. **Performance** — No dynamic dispatch; only minimal runtime overhead
4. **Extensibility** — New message or type categories can be added via template specialization
