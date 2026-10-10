# OOP Assignment Answers

## Part 1: Theoretical Forensics

### 1. The "Heavy Class" Myth
* **Mathematical explanation:** Member functions (methods) are stored only once in the code/text segment of memory, regardless of how many object instances are created. An object's memory size is determined solely by its non-static member variables. Therefore, adding methods does not increase the RAM footprint per object instance.
* **Function location:** Functions reside in the Text / Code Segment (read-only memory) of the compiled program.
* **Compiler mechanism:** The compiler implicitly passes a hidden pointer called `this` pointer to the member function, pointing to the exact memory address of the object instance being modified.

### 2. The Memory Map
* Global/static pointer initialized to `nullptr`: **Initialized Data segment**
* Local `int` variable: **Stack**
* The actual 50MB raw data requested via `new[]`: **Heap**
* The compiled machine code for `CalculateAverage()`: **Code / Text segment**
* Global/static `bool` declared inside a .cpp file: **Uninitialized Data (BSS) segment**

---

## Part 2: Code Review & Bug Hunting

### Snippet 1 Analysis
* **The Failure:** Dynamic memory leak. If an exception occurs or the function returns early after allocating memory via `new[]`, the `delete[]` statement is bypassed, causing a permanent memory leak in the heap.
* **The Fix:** Use RAII (Resource Acquisition Is Initialization) or smart pointers (`std::unique_ptr<double[]>` or `std::vector`), ensuring automatic deallocation when the pointer goes out of scope.