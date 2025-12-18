# 🏃 Running Training Management System in C++

This project is a **running training management system** developed in **C++**, designed to help runners organize their activity records in a **practical, clear, and efficient** way using the terminal.

The system allows users to register multiple training sessions, automatically calculate key metrics, and analyze performance through **different sorting filters**. The program keeps running until the user chooses to exit, allowing continuous interaction without restarting.

⚠️ **Important note:**  
This project was developed **using only the concepts studied during the first semester of university**, without relying on advanced libraries or topics beyond that scope.

---

## 🎯 Project Objective

The main goal is to provide a **simple terminal-based tool** that automates calculations and organizes running history, serving as an academic project to reinforce knowledge of **programming logic and basic data structures in C++**.

---

## 📌 Main Features

- Registration of up to **50 running sessions**
- Detailed training records including:
  - 📅 Training date
  - 📏 Distance covered (km)
  - ⏱️ Duration (minutes)
  - ⚡ Pace (automatically calculated)
- Automatic calculation of **average pace (min/km)**
- Strict date validation:
  - Valid days and months
  - Proper handling of **leap years**
- Flexible sorting system with the following criteria:
  - Date
  - Pace
  - Duration
  - Distance
- Sorting options:
  - Ascending
  - Descending
- Interactive menu that allows the user to:
  - Add new training sessions
  - Change sorting filters
  - View reorganized data without restarting the program
  - Exit the system only when desired

---

## 🧠 Programming Concepts Applied

All concepts used in this project are part of the **first semester of the undergraduate program**:

- Use of **structs** and nested structs
- Arrays of structs for storing multiple records
- Parameter passing by reference
- Modular function design
- Conditional structures (`if`, `switch`)
- Loop structures (`for`, `while`, `do-while`)
- Comparison-based sorting algorithms
- User input validation
- Program flow control
- Output formatting and decimal precision using `iomanip`

---

## 🧮 Pace Calculation

Pace is calculated automatically using the formula:
pace = duration_in_minutes / distance_in_km


The result is displayed with **two decimal places**, making it easier to analyze running performance.

---

## ▶️ How to Run the Project

### Requirements
- A C++ compiler installed (e.g., `g++`)
- Terminal or command prompt

### Steps

1. Download the source code file  
2. Open the terminal in the folder where the file is located  
3. Compile the program:
   ```bash
   g++ sistema_corrida.cpp -o system

Run the program:
Linux / macOS:
./system

Windows:
system.exe

---

## 🏗️ Project Structure
Running-Training-System/
│
├── sistema_corrida.cpp
└── README.md

📖 General Workflow
1. The user chooses whether to add training sessions or exit
2. The user enters the number of training sessions to be registered
3. Training data is filled in
4. The system automatically calculates the pace
5. The user selects the sorting criterion and order
6. The training sessions are displayed in an organized format
7. The process can be repeated as many times as desired

---

## Author

This project was developed as part of academic studies in C++, focusing on practicing programming logic and basic data structures.
Author








