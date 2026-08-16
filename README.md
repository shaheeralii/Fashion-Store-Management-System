# Shaheer's Fashion Designing Store — Fashion Store Management System

A console-based C++ application for managing fashion product design records, designed and implemented independently under a strict time constraint and without internet access, as an Open-Ended Lab Exam Finals project for the 1st Semester Computer Programming Lab course.

## Overview

The program lets a fashion store owner add product design records, look up any record by ID to see its cost, revenue, and profit breakdown, and identify the single most profitable design across all stored records. All records can be saved to and loaded from a local text file, making the data persistent across sessions.

## Features

| Feature | What It Does |
|---|---|
| Add Products | Captures design ID, name, make price, sell price, and units sold for a new record |
| Revenue Analysis | Looks up a product by ID and reports total cost, revenue, profit/loss, and demand category |
| Most Profitable Design | Scans all records and reports the one with the highest profit |
| Save to File | Writes all current records to `productdetails.txt` |
| Load from File | Reads previously saved records back into memory |
| Menu-Driven Interface | A `do-while` loop repeats until the user selects Exit |

## Menu Options

```text
=== Welcome to Shaheer's Fashion Designing Store ===
1. Add a fashion Product
2. Calculate Revenue for a Product (By Search ID)
3. Find Most Profitable Design
4. Save data into the text file
5. Load data from the text file
6. Exit
```

## Feature Details

**Product Management.** `addprodDetails()` collects a new design's ID, name (via `getline`), make price, sell price, and units sold, then computes `total_make_cost` as `make_price × total_units_sold` and appends the record to the array, guarded by a capacity check against `maxSize`.

**Revenue Analysis.** `calcRevenue()` searches for a design by ID and, if found, computes `makeCost = make_price × units_sold` and `revenue = sell_price × units_sold`, reports `profitLoss = revenue - makeCost`, and classifies the design's demand.

**Profitability Analysis.** `expensiveDesign()` iterates over every stored record, recomputing profit for each and tracking the highest value seen, then reports that record's ID, name, and profit.

**File Persistence.** `saveToFile()` writes the record count followed by all six fields per product to `productdetails.txt`; `LoadFromFile()` reads the same format back, using `ignore()` to safely mix `>>` and `getline()` around the string field.

## Concepts & Technical Implementation

- **Conditional logic** — menu dispatch uses `switch`; demand classification and record-capacity checks use `if-else`
- **Loops** — the main menu runs in a `do-while` loop; all record scans (search, profitability comparison, save, load) use `for` loops
- **Functions, by value and by reference** — `count` is passed by reference (`int &count`) in `addprodDetails()`, `saveToFile()`, and `LoadFromFile()` so the caller's record count updates directly; `calcRevenue()` and `expensiveDesign()` take `count` by value for read-only iteration
- **Arrays and strings** — a fixed-size `Product array[100]` holds all records; `std::string` with `getline()` handles multi-word design names
- **File handling** — `<fstream>` with `ofstream`/`ifstream`, each wrapped with an open-check and a status message
- **Structs** — a single `Product` struct groups all per-design fields

## Data Structure

| Field | Type | Purpose |
|---|---|---|
| `design_ID` | `int` | Unique identifier for the product |
| `design_name` | `string` | Name of the fashion design |
| `make_price` | `double` | Cost to manufacture one unit |
| `sell_price` | `double` | Selling price per unit |
| `total_units_sold` | `int` | Number of units sold |
| `total_make_cost` | `int` | Total manufacturing cost, auto-calculated on entry |

## Business Logic

```text
Total Cost = make_price × total_units_sold
Revenue    = sell_price × total_units_sold
Profit/Loss = Revenue - Total Cost
```

### Demand Classification

| Condition | Classification |
|---|---|
| Profit > 0 **and** units sold ≥ 20 | High Demand |
| Otherwise | Low Demand |

## File Persistence Format

`productdetails.txt` stores the record count on the first line, followed by six lines per product (ID, name, make price, sell price, units sold, total make cost):

```text
2
101
Classic Trench Coat
45
120
30
1350
102
Denim Jacket
30
90
15
450
```

## Sample Workflow

1. Launch the application.
2. Select **Option 5** to load any previously saved data.
3. Select **Option 1** to add new product designs.
4. Select **Option 2** and enter a design ID to see its revenue and demand category.
5. Select **Option 3** to find the most profitable design across all records.
6. Select **Option 4** to save all data before exiting.
7. Select **Option 6** to exit.

## Project Structure

```text
Fashion-Store-Management-System/
├── main.cpp             # Full source code
├── productdetails.txt   # Generated on save; stores product records
└── README.md
```

## Build & Run

```bash
g++ main.cpp -o store
./store
```

## Requirements

- A C++ compiler (e.g. g++)
- C++ standard library only — no external dependencies

## Known Limitations

- Array capacity is fixed at 100 products (compile-time constant); `LoadFromFile()` does not bound-check the count read from the file against this limit
- `total_make_cost` is stored as `int`, which truncates any decimal precision from the underlying price calculation
- No duplicate design-ID validation when adding products
- Data is stored as plain text with no encryption or binary format
- Exiting (Option 6) does not automatically save — unsaved records are lost unless Option 4 is used first

## Potential Future Improvements

- [ ] Bound-check loaded record count against array capacity
- [ ] Add duplicate design-ID validation
- [ ] Prompt to save unsaved changes before exiting
- [ ] Store `total_make_cost` as a `double` to preserve precision

## Technologies Used

| Technology | Purpose |
|---|---|
| C++ | Core application logic |
| Standard Library (`<iostream>`, `<string>`, `<fstream>`) | Console I/O, string handling, and file-based persistence |

## Author

**Shaheer**
1st Semester — Computer Science
Open-Ended CS Lab Exam Project
> Completed independently without external assistance.

## License

This project was submitted as academic coursework. Feel free to reference it for learning purposes.
