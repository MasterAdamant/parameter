# Parameter — Universal Type-Erased Wrapper in C++

A lightweight, C++11-compatible class that provides a universal container for storing and retrieving values of arbitrary types — similar in spirit to C#'s `object` or C++17's `std::any`, but written from scratch using type erasure.

---

## ✨ Features

- ✅ Store and retrieve values of **any type**
- 🔐 Runtime **type checking** with `std::type_index`
- 💡 **Safe value access** (with fallback)
- 🚀 Full support for **copy**, **move**, and **custom types**
- 📦 Header/cpp split with `Parameter.inl` for clean template support
- 🛠️ C++11 compatible — no modern extensions required

---

## 🔧 Usage Example

```cpp
#include "Parameter.hpp"
#include <iostream>
#include <string>

int main() {
    Parameter p1(42);
    Parameter p2(std::string("Hello"));

    std::cout << p1.getValueAs<int>() << std::endl;              // Outputs: 42
    std::cout << p2.getValueAs<std::string>() << std::endl;      // Outputs: Hello

    // Safe access fallback
    double wrong = p2.getSafeValueAs<double>(); // Returns 0.0
    std::cout << "Safe value: " << wrong << std::endl;
}
```

---

## 🛠 Build Instructions

### 📁 Folder Structure

```
/include
  ├── Parameter.hpp
  └── Parameter.inl
/src
  └── Parameter.cpp
main.cpp
```

### 🧱 Using Visual Studio 2022

1. Create an empty C++ Console App project.
2. Add `parameter.hpp`, `parameter.inl`, and `parameter.cpp` to the project.
3. Set `main.cpp` as the entry point.
4. Make sure `include/` is added to your project’s **Additional Include Directories**.

---

## 🧪 Tested Types

- [x] Primitive types: `int`, `double`, `char`, etc.
- [x] Standard types: `std::string`
- [x] Custom structs/classes
- [x] Move-only types (with care)
- [ ] Arrays and containers (in development)

---

## 💬 Credits

Built by @MasterAdamant as a learning experiment in C++ type erasure.  
Inspired by `std::any`, `boost::any`, and C#’s `object`.
Special thanks to ChatGPT 4o.
