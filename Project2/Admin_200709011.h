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

#ifndef ADMIN_200709011_H
#define ADMIN_200709011_H

#include "User_200709011.h"
#include "Member_200709011.h"

class Admin_200709011 : public User_200709011 {
public:
    void AddMember(Member_200709011 members[], int arrSize);
    void DeleteMember(Member_200709011 members[], int arrSize);
    void AddBook(Book_200709011 books[], int arrSize);
    void DeleteBook(Book_200709011 books[], int arrSize);
    void ListMembers(Member_200709011 members[], int arrSize);

private:
    static int GetIdByAccountName(const std::string& acc, Member_200709011 *members, int arrSize);
    static bool MemberAlreadyExists(const std::string& accName, Member_200709011 members[], int arrSize);
    static void AppendBook(Book_200709011 book, Book_200709011 books[], int arrSize);
    static void AppendMember(Member_200709011 member, Member_200709011 members[], int arrSize);
    static bool BookAlreadyExists(const std::string& name, const std::string& author, Book_200709011 *books, int arrSize);
};


#endif //ADMIN_200709011_H
