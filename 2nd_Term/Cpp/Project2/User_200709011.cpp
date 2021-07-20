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

#include <iostream>
#include <iomanip>
#include "User_200709011.h"
#include "Book_200709011.h"

using namespace std;

// listing books is in both admin and member so packing up.
void User_200709011::ListBooks(Book_200709011 *books, int arrSize) {
    cout << setw(10) << right << "\nID "
         << setw(17) << right << "Book Title "
         << setw(17) << right << "Author Name "
         << setw(21) << right << "Date Published "
         << setw(15) << right << "Status";

    for (int i=0; i<arrSize; ++i) {
        books[i].PrintBook();
    }
    cout << '\n';
}

bool User_200709011::LogIn(const string &acc, const string &pass) {
    return (acc == this->accountName && pass == this->password);
}

void User_200709011::SetNameSurname(const string &s) {
    this->nameSurname = s;
}

void User_200709011::SetAccountName(const string &s) {
    this->accountName = s;
}

void User_200709011::SetPassword(const string &s) {
    this->password = s;
}

void User_200709011::SetId(const int &n) {
    this->userId = n;
}

string User_200709011::GetNameSurname() {
    return this->nameSurname;
}

string User_200709011::GetAccountName() {
    return this->accountName;
}
