/****************************************************
 * Onur Alp                                         *
 * Akin                                             *
 * 200709011                                        *
 * Faculty of Engineering                           *
 * Computer Engineering                             *
 * CEN-104-50-50 | Object Oriented Programming      *
 * 2020-2021 Summer Term                            *
 * Project 2                                        *   
 * Ahmet COŞKUNÇAY                                  *
 ****************************************************/

#ifndef BOOK_200709011_H
#define BOOK_200709011_H

class Book_200709011 {
public:
    //empty constructor for array
    Book_200709011();

    // normal constructor for creating books
    Book_200709011(const std::string &title, const std::string &author, const std::string &pub);

    void PrintBook();
    void SetBookStatus(const std::string &s);
    void SetBookId(const int &n);
    void SetBookHolder(const std::string &s);
    std::string GetStatus();
    std::string GetBookTitle();
    std::string GetAuthor();
    std::string GetHolder();

protected:
    std::string bookTitle;
    std::string bookAuthor;
    std::string dateOfPub;
    std::string bookStatus;
    std::string bookHolder;
    unsigned int bookId;
};

#endif //BOOK_200709011_H
