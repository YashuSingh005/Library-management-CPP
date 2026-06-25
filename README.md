# Library Management System (C++)

## Author
**Yashu Singh**

## Overview
This is a simple **Library Management System** built using C++.  
It uses file handling to store and manage book records in a text file (`library.txt`).

The system allows users to:
- Add new books
- View all books
- Search for a book by ID
- Issue a book
- Return a book

---

## Features

### 1. Add Book
- Adds a new book record to `library.txt`
- Stores:
  - Book ID
  - Title
  - Author
  - Status (Available)

### 2. View Books
- Displays all stored book records from the file

### 3. Search Book
- Searches a book by its ID
- Displays full details if found

### 4. Issue Book
- Changes book status from `Available` to `Issued`
- Updates the file using a temporary file method

### 5. Return Book
- Changes book status from `Issued` to `Available`
- Updates the file using a temporary file method

---

## File Structure
- library.txt → Stores book records
- temp.txt → Temporary file used during update operations
- main.cpp → Source code (your program)


---

## How It Works
- Each book is stored in this format:
- ID,Title,Author,Status

## how to run 
- g++ main.cpp -o library
- ./library
