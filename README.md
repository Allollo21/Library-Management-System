# Project: Library Management System

This project is a C++ program that allows the user to manage a library of books using a simple menu-driven interface. The user can add, modify, remove, search, borrow, and return books using the library management system class. The library management system class consists of a vector of book objects as its data member.

## How to run the program

To run the program, you need a C++ compiler and an IDE (Integrated Development Environment) that supports C++. You also need to have the header files `LibrarySystem.h` and `Book.h` in the same folder as the main file `library.cpp`. You can use any compiler and IDE of your choice, such as GCC and Visual Studio Code. 

To compile the program, open the terminal or command prompt and navigate to the folder where you saved the project files. Then type the following command:

`g++ -o library library.cpp`

This will create an executable file named `library` in the same folder. To run the program, type the following command:

`./library`

The program will display a menu with eight options: 1. Add A Book, 2. Modify A Book, 3. Remove A Book, 4. Search A Book, 5. Borrow A Book, 6. Return A Book, 7. Show Books, and 8. Book Statistics. The user can enter their choice and follow the instructions on the screen.

## How the program works

The program uses a class named `LibraryManagementSystem` to store and manipulate the books. The `LibraryManagementSystem` class has a vector of `Book` objects as its data member. The `Book` class has data members such as book ID, title, author, genre, status, and borrower ID.

The `LibraryManagementSystem` class also has the following member functions:

- `AddBook()`: This function asks the user to enter the details of a new book, such as book ID, title, author, and genre. It then creates a `Book` object with these details and adds it to the vector.
- `ModifyBook()`: This function asks the user to enter the book ID of the book they want to modify. It then searches the vector for the matching book and allows the user to update any of the details, such as title, author, or genre. If the book is not found, it displays an error message.
- `RemoveBook()`: This function asks the user to enter the book ID of the book they want to remove. It then searches the vector for the matching book and removes it from the vector. If the book is not found, it displays an error message.
- `SearchBook()`: This function asks the user to enter the book ID or the title of the book they want to search. It then searches the vector for the matching book and displays its details. If the book is not found, it displays an error message.
- `BorrowBook()`: This function asks the user to enter the borrower ID and the book ID of the book they want to borrow. It then searches the vector for the matching book and updates the status and the borrower ID of the book. It also displays the due date of the book. If the book is not found, or the book is already borrowed, it displays an error message.
- `ReturnBook()`: This function asks the user to enter the borrower ID and the book ID of the book they want to return. It then searches the vector for the matching book and updates the status and the borrower ID of the book. It also displays the total amount to be paid by the borrower based on the due date and the number of days. If the book is not found, or the book is not borrowed by the borrower, it displays an error message.
- `ShowBooks()`: This function displays a submenu with two options: 1. Show Books (Unsorted) and 2. Show Books (Sorted). The user can choose to display the books in the vector either in the order they were added or in the alphabetical order of their titles.
- `BookStatistics()`: This function generates a report of the library management system, such as the total number of books, the number of available and borrowed books, the total revenue, and the most popular genre.

The main function creates a `LibraryManagementSystem` object and uses a loop and a switch statement to call the appropriate member function based on the user's choice. The loop terminates when the user chooses to exit.

## Limitations and improvements

The program has some limitations and possible improvements, such as:

- The program does not check for invalid input, such as non-numeric values, duplicate IDs, or empty strings. The program could use input validation techniques, such as `cin.fail()` or `try-catch` blocks, to handle errors and exceptions.
- The program does not allow the user to change the borrower ID or the book ID after entering them. The program could use dynamic memory allocation, such as `new` and `delete`, to create and modify the IDs at runtime.
- The program does not use any data structures, such as `map` or `set`, to store and manipulate the books. The program could use the STL (Standard Template Library) containers and algorithms, such as `find`, `sort`, or `count`, to simplify the code and improve the performance.
