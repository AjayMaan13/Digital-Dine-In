# 🍽️ Digital Dine-In - Restaurant Management System

[![C++](https://img.shields.io/badge/C++-11%2B-blue.svg)](https://en.cppreference.com/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)]()

A comprehensive console-based restaurant ordering and billing system built with modern C++ design patterns, featuring menu management, order processing, and persistent storage with memory safety.

## 🎯 Features

- 🍽️ **Interactive Menu System** - Navigate through organized food and drink categories
- 📐 **Size Selection** - Multiple size options with dynamic pricing calculations
- 📝 **Order Customization** - Special instructions and modification support for food items
- 💰 **Automatic Billing** - Tax computation and formatted receipt generation
- 💾 **Data Persistence** - CSV integration and automated bill file creation
- 🔒 **Memory Safety** - Zero memory leaks with RAII principles and proper cleanup

## 🛠️ Tech Stack

**Language:** C++11/14 with modern features and STL  
**OOP Concepts:** Abstract base classes, inheritance hierarchies, polymorphism  
**Design Patterns:** Template Method, Factory, RAII implementation  
**Memory Management:** Dynamic allocation, deep copy semantics, zero leaks  
**File I/O:** CSV parsing, bill generation, robust error handling

## 🚀 Quick Start

### Prerequisites
- C++11 compatible compiler (GCC 4.8+, Clang 3.4+, MSVC 2015+)
- Standard C++ library support

### Installation & Build

```bash
# Clone the repository
git clone https://github.com/AjayMaan13/Digital-Dine-In.git
cd Digital-Dine-In

# Standard build
g++ -Wall -std=c++11 -O2 *.cpp -o dinein

# Debug build with memory checking
g++ -Wall -std=c++11 -g -DDEBUG *.cpp -o dinein_debug

# Run the application
./dinein
```

## 📁 Structure

```
Digital-Dine-In/
├── Billable.cpp/.h        # Abstract base class
├── Food.cpp/.h           # Food item implementation
├── Drink.cpp/.h          # Drink item implementation
├── Menu.cpp/.h           # Menu display system
├── Ordering.cpp/.h       # Main order logic
├── Utils.cpp/.h          # Helper functions
├── main.cpp             # Application entry
├── foods.csv            # Food menu data
└── drinks.csv           # Drink menu data
```

## 💻 Usage Examples

### Basic Operations

```cpp
// Initialize and run restaurant system
Ordering restaurant;
restaurant.loadMenu();   // Load CSV data
restaurant.run();        // Start ordering
restaurant.printBill();  // Generate receipt
```

### Menu System

```
Seneca Restaurant 
 1- Order
 2- Print Bill
 3- Start a New Bill
 4- List Foods
 5- List Drinks
 0- End Program
> 
```

### Sample Bill Output

```
Bill # 001 =============================
Orange Juice................MID..   2.62
Hamburger...................Adult  12.00
                     Total:        14.62
                     Tax:           1.90
                     Total+Tax:    16.52
========================================
```

## 🏗️ Architecture

### Class Hierarchy

```
Billable (Abstract Base Class)
├── Food (Concrete Implementation)
└── Drink (Concrete Implementation)

Menu System
├── Menu (Container Class)
└── Ordering (Main Controller)
```

### Design Patterns Implementation

- **Template Method Pattern** - `Billable::read()` defines algorithm structure
- **Factory Pattern** - Dynamic object creation based on menu selection
- **RAII Pattern** - Automatic resource management and cleanup
- **Polymorphism** - Virtual functions for customized item behavior



## 🧪 Testing

```bash
# Memory leak testing (Linux/macOS)
valgrind --leak-check=full ./dinein
# Expected: "All heap blocks were freed -- no leaks are possible"
```

**Coverage:** Menu navigation, order processing, bill calculation, file I/O, memory management, error handling

## 📊 Stats

- **2,000+ lines** of C++11 code
- **7 core classes** with inheritance hierarchy
- **Zero memory leaks** through RAII implementation
- **Multiple design patterns** professionally applied
- **Cross-platform** compatibility (Windows, Linux, macOS)

## 👨‍💻 Author

**Ajaypartap Singh Maan**  
[GitHub](https://github.com/AjayMaan13) • [LinkedIn](https://linkedin.com/in/ajaypartap-singh-maan) • ajayapsmaanm13@gmail.com

---

⭐ **Star if helpful!**
