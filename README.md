# 🧵 Shaheer's Fashion Designing Store — Fashion Store Management System

We were assigned to develop a console-based C++ application to manage fashion product records for a designing store. This is developed independently as an **Open-Ended Lab Exam Finals project** for the 1st Semester CS course.

---

## 📌 Project Overview

This program allows a fashion store owner to manage product designs by storing, retrieving, analyzing, and persisting product data through a simple text-based menu interface. All data can be saved to and loaded from a local file, making it persistent across sessions.

---

## ✨ Features

| Feature | Description |
|---|---|
| ➕ Add Products | Input and store product design details |
| 📊 Revenue Analysis | Calculate cost, revenue, profit/loss for any product by ID |
| 🏆 Most Profitable Design | Automatically find the highest-profit product |
| 💾 Save to File | Persist all records to `productdetails.txt` |
| 📂 Load from File | Restore previously saved records from file |
| 🔁 Loop-Driven Menu | Continuous operation until the user chooses to exit |

---

## 🧠 Concepts & Techniques Demonstrated

This project was built to demonstrate the following core CS concepts taught in the 1st semester:

### 🔀 Conditional Logic (`if-else`, `switch`)
- Menu navigation is handled using a `switch` statement
- Revenue categorization (High Demand / Low Demand) uses `if-else` logic based on profit and units sold

### 🔁 Loops and Iteration
- The main menu runs in a `do-while` loop until the user selects Exit
- Product arrays are traversed using `for` loops in search, analysis, and file operations

### 🧩 Functions — By Value & By Reference, Modular Programming
- `addprodDetails(Product arr[], int maxSize, int &count)` — `count` is passed **by reference** so the actual count updates globally
- `calcRevenue(Product arr[], int count)` — `count` passed **by value**, read-only
- `expensiveDesign(Product arr[], int count)` — standalone modular function for profit comparison
- `saveToFile(...)` and `LoadFromFile(...)` — dedicated file I/O functions keeping `main()` clean

### 📦 Arrays and Strings
- A fixed-size array of `Product` structs (max 100 records) stores all data
- `std::string` is used for design names; `getline()` handles multi-word input correctly

### 📁 File Handling
- Uses `<fstream>` with `ofstream` (write) and `ifstream` (read)
- Saves and loads the record count + all fields for each product
- Includes error handling for failed file operations

### 🏗️ Structs
- A `Product` struct encapsulates all related fields: `design_ID`, `design_name`, `make_price`, `sell_price`, `total_units_sold`, and `total_make_cost`

---

## 🖥️ Menu Options

```
=== Welcome to Shaheer's Fashion Designing Store ===
1. Add a fashion Product
2. Calculate Revenue for a Product (By Search ID)
3. Find Most Profitable Design
4. Save data into the text file
5. Load data from the text file
6. Exit
```

---

## 📂 File Structure

```
project/
│
├── main.cpp               # Full source code
├── productdetails.txt     # Auto-generated on save (stores product records)
└── README.md              # This file
```

---

## ▶️ How to Run

### Requirements
- A C++ compiler (e.g., GCC via MinGW, or MSVC)
- Any IDE: Visual Studio, Code::Blocks, Dev-C++, or terminal

### Compile & Run (Terminal)
```bash
g++ main.cpp -o store
./store
```

### Using an IDE
1. Open `main.cpp` in your IDE
2. Build/Compile the project
3. Run the executable and interact via the console menu

---

## 💡 Sample Workflow

1. **Start** the program
2. Select **Option 5** to load any previously saved data
3. Select **Option 1** to add new product designs
4. Select **Option 2** and enter a Design ID to see its revenue and demand category
5. Select **Option 3** to find the most profitable design across all records
6. Select **Option 4** to save all data before exiting
7. Select **Option 6** to exit

---

## 📝 Product Fields

| Field | Type | Description |
|---|---|---|
| `design_ID` | `int` | Unique identifier for the product |
| `design_name` | `string` | Name of the fashion design |
| `make_price` | `double` | Cost to manufacture one unit |
| `sell_price` | `double` | Selling price per unit |
| `total_units_sold` | `int` | Number of units sold |
| `total_make_cost` | `int` | Total manufacturing cost (auto-calculated) |

---

## 📊 Demand Classification Logic

A product is classified as **High Demand** if:
- `Profit > 0` (revenue exceeds cost), **AND**
- `Total Units Sold >= 20`

Otherwise, it is classified as **Low Demand**.

---

## ⚠️ Known Limitations

- Array capacity is fixed at **100 products** (compile-time constant)
- `total_make_cost` is stored as `int`, which may lose precision for large decimal prices
- No duplicate ID validation when adding products
- Data is stored in a plain text file (no encryption or binary format)

---

## 👤 Author

**Shaheer**
1st Semester — Computer Science
Open-Ended CS Lab Exam Project
> Completed independently without external assistance.

---

## 📄 License

This project was submitted as academic coursework. Feel free to reference it for learning purposes.
