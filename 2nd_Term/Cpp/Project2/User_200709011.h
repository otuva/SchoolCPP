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

#ifndef USER_200709011_H
#define USER_200709011_H

#include "Book_200709011.h"

class User_200709011 {
public:
    void ListBooks(Book_200709011 books[], int arrSize);
    bool LogIn(const std::string &acc, const std::string &pass);
    void SetNameSurname(const std::string &s);
    void SetAccountName(const std::string &s);
    void SetPassword(const std::string &s);
    void SetId(const int &n);
    std::string GetNameSurname();
    std::string GetAccountName();

protected:
    std::string nameSurname;
    std::string accountName;
    std::string password;
    unsigned int userId;
};

#endif //USER_200709011_H
