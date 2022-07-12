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
#include "Member_200709011.h"

using namespace std;

// empty constructor for array
Member_200709011::Member_200709011() {}

// actual constructor for members
Member_200709011::Member_200709011(const string &name, const string &acc, const string &mType) {
    this->SetNameSurname(name);
    this->SetAccountName(acc);
    this->SetMemberType(mType);
    this->SetPassword("temp");
    this->heldBooks = 0;
}

// member type check
void Member_200709011::SetMemberType(const string &s) {
    if (s=="Student" || s=="Personnel" || s=="FacultyMember") {
        memberType = s;
    }
// if not one of three. set to student.
    else {
        cout << "\nMember type is not valid.\nValid types are: 'Student', 'Personnel', 'FacultyMember'\nSetting up to 'Student'.\n\n";
        memberType = "Student";
    }
}

void Member_200709011::FindBooks(Book_200709011 *books, int arrSize) {
    string title;
    string auth;

    cout << "\nEnter book name: ";
    cin >> title;
    cout << "Enter author name: ";
    cin >> auth;

    cout << "\n    Found Books:";
    cout << setw(10) << right << "\nID "
         << setw(17) << right << "Book Title "
         << setw(17) << right << "Author Name "
         << setw(21) << right << "Date Published "
         << setw(15) << right << "Status";

    // title-fill/author-fill/title-author
    for (int i=0; i<arrSize; ++i) {
        // checking if author or title has a wildcard character
        if ((books[i].GetBookTitle()==title && books[i].GetAuthor()==auth) ||
            (books[i].GetBookTitle()==title && auth=="*")                  ||
            (title=="*" && books[i].GetAuthor()==auth)) books[i].PrintBook(); // one line statement
                                                                              // so not using curly brackets
//            // if both are wildcard then print out error.
//        else if (title=="x" && auth=="*") cout << "Use 'list books' to list all books." << endl; return;
    }
    cout << '\n';
}

void Member_200709011::BorrowBook(Book_200709011 *books) {

    // borrowing limits
    if ((this->memberType=="Student"&&this->heldBooks>=5)        ||
        (this->memberType=="Personnel" && this->heldBooks>=3)    ||
        (this->memberType=="FacultyMember" && this->heldBooks>=10)) cout << "You can't borrow too much book.\n";
    else {
        static unsigned int bookId;
        cout << "\nBook Id: ";
        cin >> bookId;
        if (books[bookId].GetStatus()=="Unhold") this->MemberBorrowedABook(bookId, books);
        else if (books[bookId].GetStatus()=="Hold") cout << "The book has been borrowed by another member.\n";
        else if (books[bookId].GetStatus().empty()) cout << "Book doesn't exist.\n";
    }
}

void Member_200709011::ReturnBook(Book_200709011 *books) {
    int bookId;

    cout << "\nBook Id: ";
    cin >> bookId;

    if (books[bookId].GetStatus()=="Hold" && books[bookId].GetHolder()==this->accountName) {
        this->heldBooks -= 1;
        books[bookId].SetBookStatus("Unhold");
        cout << "You returned a book.\n";
    }
    else {
        cout << "Error. You can't return this book.\n";
    }
}

void Member_200709011::PrintMember() {
    // if not empty. print
    if (!this->accountName.empty()) {
        cout << '\n'
             << setw(6) << left << this->userId
             << setw(17) << left << this->nameSurname
             << setw(18) << left << this->memberType
             << setw(12) << left << this->accountName;
    }
}

void Member_200709011::MemberOps() {
    string newPass;

    cout << "\nEnter a new password: ";
    cin >> newPass;

    this->SetPassword(newPass);
    cout << "Updated password." << endl;
}

int Member_200709011::GetMemberIdByAccountName(const string &acc, Member_200709011 *members, int arrSize) {
    for (int i=0; i<arrSize;++i) {
        if (members[i].GetAccountName()==acc) {
            return i;
        }
    }
    return -1;
}

// if user can borrow a book. update status, held books and holder account.
void Member_200709011::MemberBorrowedABook(unsigned int bookId, Book_200709011 *books) {
    this->heldBooks += 1;
    books[bookId].SetBookStatus("Hold");
    books[bookId].SetBookHolder(this->accountName);
    cout << "You borrowed a book." << endl;
}
