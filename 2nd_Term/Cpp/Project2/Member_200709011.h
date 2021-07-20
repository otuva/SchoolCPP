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

#ifndef MEMBER_200709011_H
#define MEMBER_200709011_H

#include "User_200709011.h"
#include "Book_200709011.h"

class Member_200709011 : public User_200709011 {
public:
    // empty constructor for array
    Member_200709011();
    Member_200709011(const std::string &name, const std::string &acc, const std::string &mType);
    void SetMemberType(const std::string &s);
    void FindBooks(Book_200709011 books[], int arrSize);
    void BorrowBook(Book_200709011 books[]);
    void ReturnBook(Book_200709011 books[]);
    void PrintMember();
    void MemberOps();
    int GetMemberIdByAccountName(const std::string& acc, Member_200709011 members[], int arrSize);

private:
    void MemberBorrowedABook(unsigned int bookId, Book_200709011 books[]);
    std::string memberType;
    int heldBooks;
};

#endif //MEMBER_200709011_H
