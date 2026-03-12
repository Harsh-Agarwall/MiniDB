# MiniDB – A Lightweight Database Engine in C++

MiniDB is a small experimental database engine built in C++ to demonstrate how basic database systems work internally.
It supports dynamic records, indexing using a Red-Black Tree, command-line queries, and file-based persistence.

The project was created to understand core database concepts such as indexing, storage layers, and query execution.

---

## Features

* **Dynamic Rows** – Records are stored as key-value pairs (`field=value`)
* **Red-Black Tree Index** – Provides efficient `O(log n)` insert and search operations
* **File Persistence** – Data is stored in `data.txt` and restored when the database restarts
* **Command Line Interface** – Simple query commands
* **Basic Query Operations**

  * `INSERT`
  * `SELECT`
  * `DELETE`
  * `PRINT`

---

## Project Architecture

The system is divided into layers similar to real database systems.

```
User Input (CLI)
        │
        ▼
Query Parser (main.cpp)
        │
        ▼
Database Layer (database.cpp)
        │
        ▼
Index Layer (Red-Black Tree)
        │
        ▼
Storage Layer (File System)
```

### Components

| File           | Purpose                                  |
| -------------- | ---------------------------------------- |
| `main.cpp`     | Command-line interface and query parsing |
| `database.cpp` | Query execution layer                    |
| `rbtree.cpp`   | Red-Black Tree indexing implementation   |
| `storage.cpp`  | File-based persistence                   |
| `data.txt`     | Stores database records                  |

---

## Data Storage Format

Records are stored in a key-value format.

Example row:

```
id=1,name=Harsh,age=21,city=Delhi
```

---

## Supported Commands

### Insert Record

```
INSERT id=1 name=Harsh age=21 city=Delhi
```

### Select Record by ID

```
SELECT 1
```

### Delete Record

```
DELETE 1
```

### Print All Records

```
PRINT
```

### Exit Program

```
EXIT
```

---

## Example Run

```
MiniDB > INSERT id=1 name=Harsh age=21 city=Delhi
Inserted

MiniDB > INSERT id=2 name=Rahul age=22
Inserted

MiniDB > SELECT 1
id=1 name=Harsh age=21 city=Delhi

MiniDB > PRINT
1 -> id=1 name=Harsh age=21 city=Delhi
2 -> id=2 name=Rahul age=22

MiniDB > DELETE 1
Deleted
```

---

## Time Complexity

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(log n)   |
| Search    | O(log n)   |
| Delete    | O(log n)   |
| Print All | O(n)       |

The Red-Black Tree ensures that the height of the tree remains balanced, allowing efficient lookup operations.

---

## How It Works

1. User enters a command in the CLI.
2. The command is parsed into key-value pairs.
3. The `Database` layer processes the query.
4. Records are indexed using a Red-Black Tree.
5. Data is also saved to disk (`data.txt`) for persistence.
6. On startup, the database reloads records from disk.

---

## How to Compile

Compile using g++:

```
g++ main.cpp database.cpp storage.cpp rbtree.cpp -o MiniDB
```

Run the database:

```
./MiniDB
```

---

## Learning Objectives

This project was built to understand:

* Data structures used in database systems
* Indexing using balanced trees
* File-based storage
* Query parsing
* Layered system design

---

## Possible Improvements

Future enhancements could include:

* Full Red-Black Tree deletion with rebalancing
* Range queries (`SELECT id BETWEEN X AND Y`)
* Secondary indexes (search by fields like name)
* Multiple tables
* Transaction support
* B+ Tree indexing (used in real databases)

---

## Inspiration

This project is inspired by how real database engines structure their core components such as indexing, storage engines, and query execution layers.

---

## Author

Harsh Agarwal
B.Tech Computer Science
