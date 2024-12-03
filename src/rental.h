#ifndef RENTAL_H
#define RENTAL_H

#include <string>

class Rental {
private:
    int transactionId;
    int bookId;
    std::string renterName;

public:
    Rental(int transactionId, int bookId, const std::string& renterName);

    // Getters
    int getTransactionId() const;
    int getBookId() const;
    std::string getRenterName() const;

    // Utility
    std::string toString() const;
};

#endif