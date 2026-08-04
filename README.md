# 📒 Address Book Management System (C)

A simple "Address Book Management System" developed in "C" that allows users to store, search, edit, delete, and manage contact information using file handling. The project demonstrates the use of structures, modular programming, file operations, and input validation in C.

## ✨ Features

- ➕ Add new contacts
- 🔍 Search contacts
  - By Name
  - By Phone Number
  - By Email
- ✏️ Edit existing contacts
- ❌ Delete contacts
- 📋 List all contacts
- 💾 Save contacts to file
- 📂 Load contacts automatically on startup
- ✅ Input validation for phone numbers and email addresses
- 🏗️ Modular implementation using multiple source files


## 📁 Project Structure

AddressBook/
│── main.c              # Main menu and program execution
│── contact.c           # Add contact functionality
│── contact.h           # Structures and function declarations
│── file.c              # Load contacts from file
│── file.h              # File handling declarations
│── validation.c        # Email and phone validation
│── search.c            # Search contacts
│── edit.c              # Edit contacts
│── delete.c            # Delete contacts
│── list.c              # Display all contacts
│── save.c              # Save contacts to file
│── contact.txt         # Contact database


## 🛠️ Technologies Used

- C Programming
- Structures
- Arrays
- Functions
- Modular Programming
- File Handling
- String Manipulation
- Input Validation


## 📌 Data Stored

Each contact contains:

- Name
- Phone Number
- Email Address

Example:
Name  : Abhishek
Phone : 9880156153
Email : abhibeatz096@gmail.com


## 🚀 How to Compile

Using GCC: gcc *.c
Windows (MinGW): addressbook.exe


## 📷 Sample Menu
========== ADDRESS BOOK ==========

1. Create Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. List Contacts
6. Save Contacts
7. Exit

Enter your choice: 


## 💡 Concepts Demonstrated

- Structures
- Header Files
- Modular Programming
- File Handling (`fopen`, `fclose`, `fprintf`, `fscanf`)
- String Functions
- Input Validation
- Menu-Driven Programming
- Function Decomposition


## 🎯 Learning Outcomes

This project helps understand:

- Organizing large C programs
- Working with multiple source files
- Persistent data storage
- Contact management logic
- Validation of user input
- Modular software development


## 🔮 Future Improvements

- Sort contacts alphabetically
- Password protection
- Duplicate contact detection
- Import/Export CSV
- Update contact photo
- Backup and restore contacts
- Better terminal UI
- Dynamic memory allocation
