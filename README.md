<img src="./assets/icon_background.png" />

#  AXISQL (Advanced X-tended Indexing SQL)

A lightweight, modular SQL database engine built from scratch in C.

## 📌 Overview
AXISQL is a **low-level, high-performance SQL database engine** designed for developers who seek maximum control over data storage and retrieval. Written entirely in **C/C++**, it bypasses standard database libraries to offer a minimalistic yet powerful approach to relational data management.

## 🎯 Features
- Customizable SQL-like Query Processing: Execute fundamental **CRUD operations** (``CREATE``, ``READ``, ``UPDATE``, ``DELETE``).

- User-Defined Tables & Typed Columns: Supports ``STRING``, ``NUMBER``, ``BOOLEAN``, and ``BINARY``.

- Lightweight Storage System: Uses structured binary files for persistent data management.

- Optimized for Direct Memory Manipulation: Designed for efficiency without relying on external DBMS engines.

- Future Expansion for Indexing & Transactions: Plans for ACID-compliant operations and indexing optimization.


## Installation & Usage

#### 1️⃣ Building the Project
Compile **AXISQL** using **make**:

```sh
make
```
#### 2️⃣ Running AXISQL
Execute the **binary**:
```sh
./build/axisql # This is SDK, If you want to test a place to run AXISQL, the best option is to use axiscli, and it is in the build folder.
```

And that's it, you're now running AxiSQL on your computer!!

## 📄 License
**AXISQL** is licensed under **GPLv3—meaning** it's open-source, free to use, and encourages collaboration.