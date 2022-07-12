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
#include "Book_200709011.h"

using namespace std;

// default empty constructor for array
Book_200709011::Book_200709011() {}

// constructor for actual books
Book_200709011::Book_200709011(const string &title, const string &author, const string &pub) {
    this->bookTitle=title;
    this->bookAuthor=author;
    this->dateOfPub = pub;
    this->bookStatus = "Unhold";
}

void Book_200709011::PrintBook() {
    //if it's empty dont print
    if (!this->bookTitle.empty()) {
        cout << '\n'
             << setw(10) << left << this->bookId
             << setw(17) << left << this->bookTitle
             << setw(17) << left << this->bookAuthor
             << setw(21) << left << this->dateOfPub
             << setw(15) << left << this->bookStatus;
    }
}

// other functions to get or set
void Book_200709011::SetBookStatus(const string &s) {
    this->bookStatus = s;
}

void Book_200709011::SetBookId(const int &n) {
    this->bookId = n;
}

void Book_200709011::SetBookHolder(const string &s) {
    this->bookHolder = s;
}

string Book_200709011::GetStatus() {
    return this->bookStatus;
}

string Book_200709011::GetBookTitle() {
    return this->bookTitle;
}

string Book_200709011::GetAuthor() {
    return this->bookAuthor;
}

string Book_200709011::GetHolder() {
    return this->bookHolder;
}
