#include "BookInfo.h"

BookInfo::BookInfo() {
    this->author = "";
    this->category = "";
    this->numberOfPages = 0;
    this->isAvailable = false;
}

BookInfo::BookInfo(std::string author, std::string category, int numberOfPages, bool isAvailable) {
    this->author = author;
    this->category = category;
    this->numberOfPages = numberOfPages;
    this->isAvailable = isAvailable;
}

BookInfo::BookInfo(const BookInfo& bookInfo) {
    this->author = bookInfo.author;
    this->category = bookInfo.category;
    this->numberOfPages = bookInfo.numberOfPages;
    this->isAvailable = bookInfo.isAvailable;
}

BookInfo& BookInfo::operator=(const BookInfo& bookInfo) {
    this->author = bookInfo.author;
    this->category = bookInfo.category;
    this->numberOfPages = bookInfo.numberOfPages;
    this->isAvailable = bookInfo.isAvailable;
    return *this;
}

BookInfo::~BookInfo() {}

std::ostream& operator<<(std::ostream& stream, const BookInfo& info) {
    stream << "Author: " << info.author << std::endl<< "Category: " << info.category << std::endl << "Number of pages: " << info.numberOfPages << std::endl << "Status: ";
    if (info.isAvailable) {
        stream << "on the bookshelf" << std::endl; 
    } else {
        stream << "borrowed" << std::endl;
    }
    return stream;
}
