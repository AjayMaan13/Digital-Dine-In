# 🍽️ Digital Dine-In– Restaurant Management System

**Duration:** March 2024 – April 2024  
**Language:** C++  
**Core Concepts:** OOP, Polymorphism, Dynamic Memory, File Handling, CLI UX

---

## 📖 Overview

**Dine-In Digital** is a console-based C++ application simulating the dine-in experience of a restaurant through a command-line interface. Designed to aid waitstaff, it handles tasks like taking food and drink orders, generating detailed bills, and storing them in uniquely named files. The project was incrementally developed over five milestones, incorporating industry-relevant software engineering techniques.

---

## ✨ Features

- 📋 **Interactive Ordering System** – Navigate menus, customize orders, and select item sizes.
- 🧾 **Automated Bill Generation** – Calculate totals, taxes, and persist bills with unique filenames.
- 🔐 **Input Validation** – Prevents crashes with strict input error handling and user guidance.
- 💾 **CSV-Driven Menus** – Food and drink data are loaded dynamically from external CSV files.
- 🧠 **Object-Oriented Architecture** – Uses polymorphism with an abstract base class `Billable`.
- 🛠️ **Memory-Safe Design** – Dynamic memory managed through clear allocation/deallocation strategies.

---

## 🧰 Tech & Concepts

- C++11 Standard
- Class Hierarchies & Polymorphism
- Encapsulation & Const-Correctness
- Dynamic Memory Allocation
- CSV File Parsing & File I/O
- CLI Menu Design & UX Flow
- Exception-Free Error Handling

---

## 🧩 Project Structure

```
├── Billable.cpp / .h      # Abstract base class for billable items
├── Food.cpp / .h          # Food item class (derived from Billable)
├── Drink.cpp / .h         # Drink item class (derived from Billable)
├── Menu.cpp / .h          # Menu system for displaying/selecting items
├── Ordering.cpp / .h      # Order management & billing logic
├── Utils.cpp / .h         # Helper functions for input, memory, etc.
├── constants.h            # Global settings and constants
├── foods.csv / drinks.csv # Menu item data (external input)
├── bill_1.txt, ...        # Sample output bill files
├── main.cpp               # Program entry point
└── README.md              # This file
```

---

## 🧠 Learning Outcomes

- Applied clean object-oriented design with real-world restaurant modeling.
- Used dynamic memory effectively to handle runtime input and objects.
- Practiced CLI-based UX design and CSV-driven data processing.
- Reinforced concepts of file I/O and class inheritance hierarchies.

---

## 🧪 Sample Program Flow

```
Seneca Restaurant 
 1- Order
 2- Print Bill
 3- Start a New Bill
 4- List Foods
 5- List Drinks
 0- End Program
> 1
   Order Menu
    1- Food
    2- Drink
    0- Back to main menu
   > 2
      Drink Menu
       1- Pepsi
       2- Orange Juice
       3- Coffee
       0- Back to Order
      > 2
         Drink Size Selection
          1- Small
          2- Medium
          3- Large
          4- Extra Large
          0- Back
         > 2
   Order Menu
    1- Food
    2- Drink
    0- Back to main menu
   > 0
> 2
Bill #001 =============================
Orange Juice................MID..   2.62
                     Total:         2.62
                     Tax:           0.34
                     Total+Tax:     2.97
========================================
```

---

## 🚀 How to Build & Run

```bash
g++ -Wall -std=c++11 -g -o dinein main.cpp *.cpp
./dinein
```

To check memory leaks (Linux/macOS):
```bash
valgrind --leak-check=full --track-origins=yes ./dinein
```

---

## 🙋 About the Developer

**Ajaypartap Singh Maan**  
📧 ajayapsmaanm13@gmail.com  
💼 Ajaypartap Singh Maan | AjayMaan13

---

## 🏷️ Tags

`C++` `OOP` `Restaurant System` `Billing App` `CLI` `File Handling` `Dynamic Memory` `Polymorphism` `CSV Parsing`