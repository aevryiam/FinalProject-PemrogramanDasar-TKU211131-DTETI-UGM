#include "rental.h"
#include <sstream>

// Constructor
Rental::Rental(int transactionId, int bookId, const std::string& renterName)
    : transactionId(transactionId), bookId(bookId), renterName(renterName) {}

// Getters
int Rental::getTransactionId() const {
    return transactionId;
}

int Rental::getBookId() const {
    return bookId;
}

std::string Rental::getRenterName() const {
    return renterName;
}

// Utility
std::string Rental::toString() const {
    std::ostringstream oss;
    oss << transactionId << "," << bookId << "," << renterName;
    return oss.str();
}