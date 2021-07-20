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
#include "Book_200709011.h"
#include "Member_200709011.h"
#include "Admin_200709011.h"

using namespace std;

void AdminMenu(Admin_200709011 admin, Book_200709011 *books, Member_200709011 *members, int arrSize) {
    string usr, pass;
    char ch;

    cout << "\nAdmin User Name: ";
    cin >> usr;

    cout << "Admin Password: ";
    cin >> pass;

    if (admin.LogIn(usr, pass)) {
        cout << "Password accepted.\n";
        while (true) {
            cout << "\n    ---Admin Menu---\n1. Add Book\n2. Delete Book\n3. List Books\n4. Add Member\n5. List Members\n6. Delete Member\n7. Exit\nEnter Your Choice: ";
            cin >> ch;
            switch (ch) {
                case '1':
                    admin.AddBook(books, arrSize);
                    continue;
                case '2':
                    admin.DeleteBook(books, arrSize);
                    continue;
                case '3':
                    admin.ListBooks(books, arrSize);
                    continue;
                case '4':
                    admin.AddMember(members, arrSize);
                    continue;
                case '5':
                    admin.ListMembers(members, arrSize);
                    continue;
                case '6':
                    admin.DeleteMember(members, arrSize);
                    continue;
                case '7':
                    return;
                default:
                    cout << "\nChoice is not valid.\n" << endl;
                    continue;
            }
        }
    }
    else {
        cout << "\nWrong Username/Password.\n";
    }
}

void MemberMenu(Book_200709011 *books, Member_200709011 *members, int arrSize) {
    char ch;
    string inpUser;
    string inpPass;

    cout << "\nMember User Name: ";
    cin >> inpUser;
    cout << "Password: ";
    cin >> inpPass;

    // it'll either return index or -1
    int memIndex = members->GetMemberIdByAccountName(inpUser, members, arrSize);

    if (members[memIndex].LogIn(inpUser, inpPass)) {
        cout << "\nPassword accepted.\n";
        while (true) {
            cout << "\n    ---Member Menu---\n1. Find Book\n2. Borrow Book\n3. Return Book\n4. List Books\n5. Member Operations\n6. Exit\nEnter Your Choice: ";
            cin>>ch;
            switch (ch) {
                case '1':
                    members->FindBooks(books, arrSize);
                    continue;
                case '2':
                    members[memIndex].BorrowBook(books);
                    continue;
                case '3':
                    members[memIndex].ReturnBook(books);
                    continue;
                case '4':
                    members->ListBooks(books, arrSize);
                    continue;
                case '5':
                    members[memIndex].MemberOps();
                    continue;
                case '6':
                    return;
                default:
                    cout << "Invalid choice.\n";
                    continue;
            }
        }
    }
    else if (memIndex==-1){
        cout << "Account name does not exist." << endl;
    }
    else {
        cout << "Wrong password." << endl;
    }
}

void MainMenu(const Admin_200709011 &admin, Book_200709011 *books, Member_200709011 *members, int arrSize) {
    char ch;
    while (true) {
        cout << "\n    ===Main Menu===\n1. Admin Login\n2. Member Login\n3. Exit\nEnter Your Choice: ";
        cin >> ch;
        switch (ch) {
            case '1':
                AdminMenu(admin, books, members, arrSize);
                continue;

            case '2':
                MemberMenu(books, members, arrSize);
                continue;

            case '3':
                return;

            default:
                cout << "\nIt's not a valid option.\n";
                continue;
        }
    }
}

int main() {
    // for safe handling
    int arrSize = 100;
    Member_200709011 members[arrSize];
    Book_200709011 books[arrSize];

    // I was going to use char arrays instead of strings. 
    // but I decided to use strings.
    Admin_200709011 admin;
    admin.SetAccountName("admin");
    admin.SetPassword("1234");

    MainMenu(admin, books, members, arrSize);

    return 0;
}
