# OOP Assignment Answers

## Part 1: Theoretical Forensics

### 1. The Chaining Enigma (Method Chaining)
- **The Problem:** The method tried to return by value (`Vector3D`) and returned a pointer (`this`), which breaks method chaining and causes a compiler error.
- **The Solution:** Methods designed for chaining must return a reference to the current object using the class reference type (`Vector3D&`) and return `*this` instead of returning a pointer or a copy.

### 2. The Shared State (Static Members)
- **Why Static?** The maximum allowed users is a system-wide property rather than a per-instance variable. Making it `static` ensures a single shared copy exists across all instances in the data segment.
- **C++17 Feature:** Using `inline static` allows direct in-class initialization, eliminating the need for old separate out-of-class definitions.

### 3. The Implicit Trap (Implicit Conversions)
- **The Mechanism:** Non-explicit constructors allow the compiler to silently and automatically convert raw types (like a raw `double`) into class objects behind the scenes during comparisons.
- **The Fix:** Adding the **`explicit`** keyword prevents these dangerous, silent, and unintended type conversions, enforcing strict safety.

---ss

## Part 2: Code Review & Sabotage Solutions

### Snippet A: The Broken Stream
- **The Problem:** `operator<<` failed to compile because as a member function, its implicit left-hand operand is always the class instance, whereas `std::cout` (of type `std::ostream`) must be on the left.
- **The Solution:** Remove it from the class and implement it as a non-member global function, using the **`friend`** keyword inside the class to safely access private members like `model_`.

```cpp
class Drone {
    std::string model_;
public:
    Drone(std::string m) : model_(m) {}

    friend std::ostream& operator<<(std::ostream& os, const Drone& d) {
        os << "Drone Model: " << d.model_;
        return os;
    }
};
```

### Snippet B: Ambiguous Math
- **The Problem:** The conversion operator `operator double()` allows implicit decay into a primitive `double`, which can cause catastrophic silent type mismatches in computational or physics engines.
- **The Solution:** Mark the conversion operator as `explicit` to enforce strict safety and prevent implicit conversions.

```cpp
class SensorValue {
    double reading_;
public:
    SensorValue(double r) : reading_(r) {}

    explicit operator double() const {
        return reading_;
    }
};
```