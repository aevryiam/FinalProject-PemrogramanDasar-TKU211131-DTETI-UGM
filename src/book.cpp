#include "book.h"
#include <sstream>

// Constructor
Book::Book(int id, const std::string& title, const std::string& author, int quantity)
    : id(id), title(title), author(author), quantity(quantity) {}

// Getters
int Book::getId() const {
    return id;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getQuantity() const {
    return quantity;
}

// Setters
void Book::setQuantity(int quantity) {
    this->quantity = quantity;
}

// Utility
std::string Book::toString() const {
    std::ostringstream oss;
    oss << id << "," << title << "," << author << "," << quantity;
    return oss.str();
}