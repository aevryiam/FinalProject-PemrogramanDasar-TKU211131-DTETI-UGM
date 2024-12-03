#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "book.h"
#include "rental.h"

std::vector<Book> loadBooks(const std::string& filename) {
    std::vector<Book> books;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id, quantity;
        std::string title, author;
        char delim;

        if (iss >> id >> delim && std::getline(iss, title, ',') &&
            std::getline(iss, author, ',') && iss >> quantity) {
            books.emplace_back(id, title, author, quantity);
        }
    }
    return books;
}

void saveBooks(const std::vector<Book>& books, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& book : books) {
        file << book.toString() << std::endl;
    }
}

void displayBooks(const std::vector<Book>& books) {
    std::cout << "Available Books:\n";
    for (const auto& book : books) {
        std::cout << book.getId() << ". " << book.getTitle() << " by " << book.getAuthor()
                  << " (Quantity: " << book.getQuantity() << ")\n";
    }
}

void addBook(std::vector<Book>& books) {
    int id, quantity;
    std::string title, author;

    std::cout << "Enter book ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter book title: ";
    std::getline(std::cin, title);
    std::cout << "Enter book author: ";
    std::getline(std::cin, author);
    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    books.emplace_back(id, title, author, quantity);
    std::cout << "Book added successfully.\n";
}

void editBook(std::vector<Book>& books) {
    int id;
    std::cout << "Enter the ID of the book to edit: ";
    std::cin >> id;
    std::cin.ignore();

    for (auto& book : books) {
        if (book.getId() == id) {
            std::string newTitle, newAuthor;
            int newQuantity;

            std::cout << "Enter new title (current: " << book.getTitle() << "): ";
            std::getline(std::cin, newTitle);
            std::cout << "Enter new author (current: " << book.getAuthor() << "): ";
            std::getline(std::cin, newAuthor);
            std::cout << "Enter new quantity (current: " << book.getQuantity() << "): ";
            std::cin >> newQuantity;

            book = Book(id, newTitle, newAuthor, newQuantity);
            std::cout << "Book updated successfully.\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void deleteBook(std::vector<Book>& books) {
    int id;
    std::cout << "Enter the ID of the book to delete: ";
    std::cin >> id;

    auto it = std::remove_if(books.begin(), books.end(), [id](const Book& book) {
        return book.getId() == id;
    });

    if (it != books.end()) {
        books.erase(it, books.end());
        std::cout << "Book deleted successfully.\n";
    } else {
        std::cout << "Book not found.\n";
    }
}

void rentBook(std::vector<Book>& books, const std::string& rentalFile) {
    int bookId;
    std::string renterName;

    displayBooks(books);

    std::cout << "Enter book ID to rent: ";
    std::cin >> bookId;
    std::cin.ignore();
    std::cout << "Enter renter's name: ";
    std::getline(std::cin, renterName);

    for (auto& book : books) {
        if (book.getId() == bookId && book.getQuantity() > 0) {
            book.setQuantity(book.getQuantity() - 1);

            std::ofstream file(rentalFile, std::ios::app);
            Rental rental(rand() % 1000, bookId, renterName);
            file << rental.toString() << std::endl;

            std::cout << "Book rented successfully!\n";
            return;
        }
    }
    std::cout << "Book not available or invalid ID.\n";
}

int main() {
    const std::string bookFile = "book.txt";
    const std::string rentalFile = "rental.txt";

    std::vector<Book> books = loadBooks(bookFile);
    std::cout << books.size() << " books loaded from file.\n";

    int choice;
    do {
        std::cout << "\n--- Book Rental System ---\n";
        std::cout << "1. Display Books\n";
        std::cout << "2. Add Book\n";
        std::cout << "3. Edit Book\n";
        std::cout << "4. Delete Book\n";
        std::cout << "5. Rent a Book\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayBooks(books);
                break;
            case 2:
                addBook(books);
                saveBooks(books, bookFile);
                break;
            case 3:
                editBook(books);
                saveBooks(books, bookFile);
                break;
            case 4:
                deleteBook(books);
                saveBooks(books, bookFile);
                break;
            case 5:
                rentBook(books, rentalFile);
                saveBooks(books, bookFile);
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}