# Book Rental System

A simple book rental system built in C++ that allows users to manage books, add/edit/delete them, and perform rental transactions. The application stores books and rental information in text files.

## Features
- **Add Books**: Allows you to add new books to the system.
- **Edit Books**: Modify details of existing books (title, author, quantity).
- **Delete Books**: Remove books from the system.
- **Display Books**: View all available books.
- **Rent Books**: Rent books by providing book ID and renter name.
- **File Persistence**: Load and save books and rental information from/to text files.

## Prerequisites

To run this application, you need:
- A C++ compiler that supports C++11 or later (e.g., GCC, MinGW, Clang).
- A basic text editor or IDE (e.g., Visual Studio Code, CLion, Code::Blocks).

## Installation

1. Clone this repository:
   ```
   git clone https://github.com/aevryiam/FinalProject-PemrogramanDasar-TKU211131-DTETI-UGM.git
   cd FinalProject-PemrogramanDasar-TKU211131-DTETI-UGM
   ```
2. Compile the C++ files using your preferred C++ compiler. For example, using g++:
   ```
   g++ -o rental_buku main.cpp book.cpp rental.cpp
   ```
3. Run the application
   ```
   ./rental_buku
   ```
   
## File Structure

- `src/` - Contains the main program files:
  - `main.cpp`: Entry point and menu logic.
  - `book.cpp`: Definition and implementation of the Book class.
  - `rental.cpp`: Definition and implementation of the Rental class.
  - `book.h`: Header file for the Book class.
  - `rental.h`: Header file for the Rental class.

- `data/` - Contains data files:
  - `book.txt`: Text file that stores the list of books (ID, Title, Author, Quantity).
  - `rental.txt`: Text file that stores rental transactions (Rental ID, Book ID, Renter Name).

## Usage

When the program starts, you will be presented with a menu with the following options:
1. Display Books - View the list of available books.
2. Add Book - Add a new book to the system.
3. Edit Book - Modify details of an existing book.
4. Delete Book - Remove a book from the system.
5. Rent a Book - Rent a book by entering its ID and your name.
6. Exit - Exit the program.

You can perform any of the operations as described in the menu, and the program will update the corresponding text files (`book.txt` and `rental.txt`) with the latest data.

## Contributing

Feel free to fork this repository, submit issues, and send pull requests. Contributions are welcome!

## Licence

This project is licensed under the GNU - see the [LICENSE](LICENSE) file for details.
