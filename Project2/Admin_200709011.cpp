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
#include "Admin_200709011.h"

using namespace std;

void Admin_200709011::AddMember(Member_200709011 *members, int arrSize) {

    //take info and create a new member object.
    cout << "\nEnter Member Info\n";
    string nameSur;
    string accName;
    string memType;

    cout << "Name-Surname: ";
    cin >> nameSur;
    cout << "Account name: ";
    cin >> accName;
    cout << "Member Type: ";
    cin >> memType;

    if (MemberAlreadyExists(accName, members, arrSize)) {
        cout << "\nA member is registered with this account name. Try again.\n";
    }
    else {
        Member_200709011 newMember(nameSur, accName, memType);
        AppendMember(newMember, members, arrSize);
    }
}

void Admin_200709011::DeleteMember(Member_200709011 *members, int arrSize) {

    // account name to index and delete it.
    string userInp;

    cout << "\nAccount name to delete: ";
    cin >> userInp;

    // it'll either return index or -1. '
    int ind = GetIdByAccountName(userInp, members, arrSize);

    if (ind == -1) {
        cout << "Account not found.\n";
    }
    else {
        for (int i=ind; i<arrSize-1; ++i) {
            members[i] = members[i+1];
            members[i].SetId(i);
        }

        cout << "Member is deleted.\n";
    }
}

void Admin_200709011::AddBook(Book_200709011 *books, int arrSize) {
    // take info create new book object
    static string name;
    static string author;
    static string pub;

    cout << "\nBook Name: ";
    cin >> name;

    cout << "Author Name: ";
    cin >> author;

    cout << "Date published [dd-mm-yyyy]: ";
    cin >> pub;

    if (BookAlreadyExists(name, author, books, arrSize)) {
        cout << "\nBook already exist.\n";
    }
    else {
        Book_200709011 cBook(name, author, pub);
        AppendBook(cBook, books, arrSize);
        cout << "Added book.\n";
    }
}

void Admin_200709011::DeleteBook(Book_200709011 *books, int arrSize) {
    int ch;
    cout << "\nEnter book id: ";
    cin >> ch;

    for (int i=ch; i<arrSize-1; ++i) {
        books[i] = books[i+1];
        books[i].SetBookId(i);
    }

    cout << "Book is deleted.\n";
}

void Admin_200709011::ListMembers(Member_200709011 *members, int arrSize) {
    cout << '\n'
         << setw(8)  << left << "ID"
         << setw(17) << left << "Name-Surname"
         << setw(16) << left << "Member Type"
         << setw(17) << left << "Account Name";

    for (int i=0; i<arrSize; ++i) {
        members[i].PrintMember();
    }
    cout << '\n';
}

int Admin_200709011::GetIdByAccountName(const string &acc, Member_200709011 *members, int arrSize) {
    for (int i=0; i<arrSize;++i) {
        if (members[i].GetAccountName()==acc) {
            return i;
        }
    }
    return -1;
}

bool Admin_200709011::MemberAlreadyExists(const string &accName, Member_200709011 *members, int arrSize) {
    for (int i=0; i<arrSize; ++i) {
        if (members[i].GetAccountName()==accName) {
            return true;
        }
    }
    return false;
}

void Admin_200709011::AppendBook(Book_200709011 book, Book_200709011 *books, int arrSize) {
    for (int i=0; i<arrSize; ++i) {
        if (books[i].GetBookTitle().empty() && books[i].GetAuthor().empty()) {
            book.SetBookId(i);
            books[i] = book;
            return;
        }
    }
}

void Admin_200709011::AppendMember(Member_200709011 member, Member_200709011 *members, int arrSize) {
    for (int i=0; i<arrSize; ++i) {
        if (members[i].GetAccountName().empty() && members[i].GetNameSurname().empty()) {
            member.SetId(i);
            members[i] = member;
            return;
        }
    }
}

bool Admin_200709011::BookAlreadyExists(const string &name, const string &author, Book_200709011 *books, int arrSize) {
    static string title;
    static string auth;
    for (int i=0;i<arrSize;++i) {
        title = books[i].GetBookTitle();
        auth = books[i].GetAuthor();

        if (title==name && auth==author) {
            return true;
        }
    }
    return false;
}
