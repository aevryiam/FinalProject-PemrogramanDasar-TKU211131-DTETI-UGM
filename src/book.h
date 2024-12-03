#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    int quantity;

public:
    Book(int id, const std::string& title, const std::string& author, int quantity);
    
    // Getters
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getQuantity() const;

    // Setters
    void setQuantity(int quantity);

    // Utility
    std::string toString() const;
};

#endif