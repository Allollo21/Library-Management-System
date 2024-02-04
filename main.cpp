#include <iostream>
#include <unistd.h>
#include "LibrarySystem.h"
#include "Book.h"
using namespace std;

LibraryManagementSystem lms;

void ShowBooksHandle()
{
    char ch;
    do
    {
        system("cls");
        system("color 0A");

        cout << "\t\t\t------------------------------------"<<endl;
        cout << "\t\t\t|--  SHOWING BOOKS DEPARTMENT  ----|"<<endl;
        cout << "\t\t\t------------------------------------"<<endl;
        cout << "\t\t\t[1] Show Books (Unsorted)"<<endl;
        cout << "\t\t\t[2] Show Books (Sorted) "<<endl;
        cout << "\t\t\t[0] Return To Main Menu"<<endl;
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch(ch)
        {
        case '1':
            lms.PrintBooksUnsorted();
            break;

        case '2':
            lms.PrintBooksSorted();
            break;

        case '0':
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            sleep(3);
        }
    }
    while(ch != '0');
}


int main()
{
    char ch;
    do
    {
        system("cls");
        system("color 0A");

        cout << "\t\t\t------------------------------------"<<endl;
        cout << "\t\t\t|--  LIBRARY MANAGEMENT SYSTEM ----|"<<endl;
        cout << "\t\t\t------------------------------------"<<endl;
        cout << "\t\t\t[1] Add A Book"<<endl;
        cout << "\t\t\t[2] Modify A Book"<<endl;
        cout << "\t\t\t[3] Remove A Book"<<endl;
        cout << "\t\t\t[4] Search A Book"<<endl;
        cout << "\t\t\t[5] Borrow A Book"<<endl;
        cout << "\t\t\t[6] Return A Book"<<endl;
        cout << "\t\t\t[7] Show Books"<<endl;
        cout << "\t\t\t[8] Book Statistics"<<endl;
        cout << "\t\t\t[0] Exit"<<endl;
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch(ch)
        {
        case '1':
            lms.AddBook();
            break;

        case '2':
            lms.ModifyBook();
            break;

        case '3':
            lms.RemoveBook();
            break;

        case '4':
            lms.SearchBook();
            break;

        case '5':
            lms.BorrowBook();
            break;

        case '6':
            lms.ReturnBook();
            break;

        case '7':
            ShowBooksHandle();
            break;

        case '8':
            lms.BookStatistics();
            break;

        case '0':
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            sleep(3);
        }
    } while(ch != '0');

    cout << "\t\t\t\tTHANK YOU!\n";
    return 0;
}
