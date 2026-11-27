# Personal Expense Management System

A console-based financial tracking application written in C that allows users to manage monthly income, log expenses, perform CRUD operations, and persist records locally.

---

## Features

* **Income Tracking:** Add to your monthly income and view the total accumulated income.
* **Expense Management:** Log expenses with a category, description, and amount (up to 500 records).
* **CRUD Operations:** View all records, search expenses by category, update existing entries by ID, and delete records.
* **Financial Calculations:** Automatically computes total expenses, remaining balance, and monthly savings.
* **Data Persistence:** Automatically loads previous session data from `records.dat` on startup and saves updates to disk.

---

## Prerequisites

* A C compiler such as **GCC** (MinGW on Windows, Clang/GCC on macOS/Linux).
* Standard C libraries (`stdio.h`, `string.h`).

---

## Getting Started

### 1. Save the Code
Save the source code into a file named `expense_manager.c`.

### 2. Compile
Open your terminal or command prompt and run:
```bash
gcc expense_manager.c -o expense_manager
```

### 3. Run
* **Linux / macOS:**
  ```bash
  ./expense_manager
  ```
* **Windows:**
  ```cmd
  expense_manager.exe
  ```

---

## Menu Options

| Option | Action | Description |
| :--- | :--- | :--- |
| **1** | Add Expense | Record a new expense with category, description, and amount. |
| **2** | Add Income | Add funds to the total monthly income. |
| **3** | Display Monthly Income | View the current total monthly income. |
| **4** | Display Expense Records | List all saved expense entries with their IDs and details. |
| **5** | Remaining Balance | View remaining funds (`Monthly Income - Total Expenses`). |
| **6** | Monthly Saving | View total monthly savings. |
| **7** | Update Expense | Modify the category, description, or amount of an expense by ID. |
| **8** | Search Category | Filter and display all expenses belonging to a specific category. |
| **9** | Calculate Total Expense | Display the sum of all recorded expenses. |
| **10** | Delete Expense | Remove an expense record permanently using its ID. |
| **11** | Save Records | Manually write current session data to `records.dat`. |
| **12** | Save and Exit | Save all changes to `records.dat` and close the program. |

---

## Data Storage Format (`records.dat`)

The application stores data in a plain-text file named `records.dat` in the same directory as the executable:

```text
<monthlyIncome> <count> <nextId>
<id>
<type>
<category>
<description>
<amount>
```

---

## Limitations

* **Fixed Capacity:** Supports a maximum of `500` records per file.
* **Case-Sensitive Search:** Category search (`strcmp`) requires an exact case match (e.g., `Food` will not match `food`).
* **Input Buffer:** Entering non-numeric characters into numeric fields (menu choice or amount) may cause unexpected looping.
