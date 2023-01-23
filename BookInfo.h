#pragma once
#include <iostream>


class BookInfo {
    public:
        std::string author;
        std::string category;
        int numberOfPages;
        bool isAvailable;
        BookInfo();
        BookInfo(std::string author, std::string category, int numberOfPages, bool isAvailable);
        BookInfo(const BookInfo& bookInfo);
        BookInfo& operator=(const BookInfo& bookInfo);
        ~BookInfo();
        friend std::ostream& operator<<(std::ostream& stream, const BookInfo& info);
};
