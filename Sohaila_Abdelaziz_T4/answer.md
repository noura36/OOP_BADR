# C++ Session 4 Assignment — Answers

---

## Part 1: Conceptual & Design Questions

### 1. The Backwards Architect
* **Question:** Why is having `Car` inherit from `Engine` a violation of the "Is-A" vs. "Has-A" relationship? What invalid operation does this design permit, how should it be refactored, and how is the relationship drawn in UML?
* **Answer:** A `Car` is not an `Engine` (`Is-A` is false); a `Car` owns/contains an `Engine` (`Has-A`). Public inheritance from `Engine` wrongly allows treating a `Car` as an `Engine` and calling `Engine` operations (such as `ignite()`) directly on a `Car`. It should be refactored to **Composition** by having an `Engine` member inside `Car`.
  * **UML Diagram:**
    ```text
    Car ◆──────── Engine
    ```

### 2. The Constructor Chain
* **Question:** What is the exact output of the snippet, what is the construction/destruction rule, and where does `log_` fit in the sequence?
* **Answer:** Construction runs from base to derived, and member objects are constructed in declaration order after the base class and before the derived class body; destruction runs in the exact reverse order. The `log_` member is constructed after `Server` finishes constructing and before `DatabaseServer`'s constructor body runs, and it is destroyed right after `DatabaseServer`'s destructor body runs and before `Server` is destroyed.
  * **Output:**
    1. `Server Booting`
    2. `Logger Opened`
    3. `DB Connected`
    4. `DB Disconnected`
    5. `Logger Closed`
    6. `Server Shutting Down`

### 3. The Ambiguity of the Diamond
* **Question:** What is the Diamond Problem, what three issues does it cause, what is the industry best practice, and why is it preferred over the language-level fix?
* **Answer:** The Diamond Problem occurs when a derived class inherits from two base classes that share a common ancestor, creating two subobjects of the top-level base inside the derived object.
  * **Three issues:**
    1. **Memory bloat:** Duplicate base subobjects waste memory.
    2. **Compiler ambiguity:** Calling inherited members can be ambiguous without qualification.
    3. **Double initialization / overhead:** The shared base is constructed more than once unless handled specially.
  * **Industry rule & why it is preferred:** Favor **Composition** over multiple inheritance (at most single inheritance + composition). It avoids complex `virtual` inheritance rules, extra indirection/overhead, and tangled hierarchies, keeping designs simpler and easier to maintain.

---

## Part 2: Code Snippets

### Snippet A: The Locked Vault
* **Question:** Why can't `VaultManager` access `access_level`? Is `access_level` still present in memory? What access specifier replaces `public` on `Vault`? Would `m.access_level = 9;` in `main()` compile?
* **Answer:** `access_level` is `private` in `Vault`, so derived classes like `VaultManager` cannot access it directly. Yes, it is still allocated in memory as part of the `Vault` subobject. Replace `public` with `protected` on `Vault` (or make `access_level` `protected` inside `Vault`) so derived classes can access it while external callers cannot. No, `m.access_level = 9;` in `main()` will **not** compile because `protected` members cannot be accessed from outside the class hierarchy.

### Snippet B: The Broken Chain
* **Question:** Why does the compiler look for a default constructor in `NetworkNode`? How should `Router`'s constructor be written? Why is adding an empty `NetworkNode() {}` while leaving `Router`'s body unchanged a bad fix?
* **Answer:** A base class subobject must be constructed before entering the derived class constructor body (`{}`). Because `Router` does not initialize `NetworkNode` in its member initializer list, the compiler tries to call `NetworkNode()`, which does not exist when a parameterized constructor is defined.
  * **Corrected `Router` constructor:**
    ```cpp
    Router(std::string ip, int ports)
        : NetworkNode(std::move(ip)), port_count(ports) {}
    ```
  * **Why `NetworkNode() {}` with unchanged body is a bad fix:** It performs extra/unnecessary work by default-constructing `NetworkNode` first and assigning `ip_address = ip;` later inside the body, which is less clean and fails if members are `const` or references.

---

## Part 3: Mini-Project Capstone — "The RPG Bestiary"

* **Question:** Implement `AttackStats`, `Monster`, `Dragon` (with inheritance and composition), `captureMonster(Monster m)`, test `sizeof` in `main()` vs. inside `captureMonster()` to demonstrate Object Slicing, and include the UML diagram at the top of the code file.
* **Answer:** Implemented in `mini_project.cpp`. Creating a `Dragon` object (`d`) and passing it **by value** to `captureMonster(Monster m)` slices off the derived `Dragon` portion (`AttackStats`), resulting in a smaller `sizeof(m)` inside `captureMonster` than `sizeof(d)` in `main()`.