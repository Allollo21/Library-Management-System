#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include <iostream>
#include "Container.h"
#include "Book.h"

using namespace std;

class LibraryManagementSystem
{
private:
    Container<Book> array;
public:
    LibraryManagementSystem() {}
    ~LibraryManagementSystem() {}


    void AddBook()
    {
        system("cls");
        system("color 7");

        Book temp;
        temp.read();
        array.AddAtEnd(temp);
        cout << "\n\t\t\t\t BOOK ADDED SUCCESSFULLY!" << endl << "\n\t\t\t\t";

        system("pause");
        system("cls");
    }

    Container<Book>::iterator IndexBook()
    {

        system("cls");
        system("color 7");

        char ch;
        string search;
        cout << "What You Wanna Search For ? \n" << "[1]. Title \n[2]. Author \n[3]. ISBN" <<endl;
        cin >> ch;
        switch(ch)
        {
        case '1':
        {
            cout << "\nEnter Title: ";
            getline(cin >> ws, search);
            for(auto i = array.begin(); i != array.end(); i++)
            {
                if(search == array[i].title)
                {
                    cout << "\t\t\t\tBOOK FOUND!" << endl;
                    return i;
                }

            }

            cout << "\t\t\t\tCould Not Find That Book!" <<endl;
            return nullptr;
            break;
        }

        case '2':
        {
            cout << "\nEnter Author: ";
            getline(cin >> ws, search);
            for(auto i = array.begin(); i != array.end(); i++)
            {

                if(search == array[i].author)
                {
                    cout << "\t\t\t\tBOOK FOUND!" << endl;
                    return i;
                }

            }

            cout << "\t\t\t\tCould Not Find That Book!" <<endl;
            return nullptr;
            break;
        }

        case '3':
        {
            cout << "\nEnter ISBN: ";
            getline(cin >> ws, search);
            for(auto i = array.begin(); i != array.end(); i++)
            {
                if(search == array[i].isbn)
                {
                    cout << "\t\t\t\tBOOK FOUND!" << endl;
                    return i;
                }

            }

            cout << "\t\t\t\tCould Not Find That Book!" <<endl;
            return nullptr;
            break;
        }

        default:
            cout << "\t\t\t\tInvalid choice. Please try again.\n\t\t\t\t" << endl;
        }

        system("pause");
        system("cls");
    }

    void RemoveBook()
    {

        system("cls");
        system("color 7");

        Container<Book>::iterator index = IndexBook();

        if(index != nullptr)
        {
            array.RemovePosition(index);
            cout << "\t\t\t\tDeleted Successfully!\n\t\t\t\t" << endl;
        }

        system("pause");
        system("cls");

    }

    void ModifyBook()
    {

        system("cls");
        system("color 7");

        Container<Book>::iterator index = IndexBook();

        if(index != nullptr)
        {
            char ch;
            string modifier;
            cout << "What You Wanna Modify ? \n" << "[1]. Title \n[2]. Author \n[3]. ISBN" <<endl;
            cin >> ch;

            switch(ch)
            {
            case '1':
            {
                cout << "\nEnter New Title: ";
                getline(cin >> ws, modifier);
                array[index].title = modifier;
                cout << "\t\t\t\tTitle Modified Successfully!\n";
                break;
            }

            case '2':
            {
                cout << "\nEnter New Author Name: ";
                getline(cin >> ws, modifier);
                array[index].author = modifier;
                break;
            }

            case '3':
            {
                cout << "\nEnter New ISBN: ";
                getline(cin >> ws, modifier);
                array[index].isbn = modifier;
                break;
            }

            default:
                cout << "\t\t\t\tInvalid choice. Please try again.\n\t\t\t\t" << endl;
            }
        }

        system("pause");
        system("cls");
    }

    void SearchBook()
    {
        system("cls");
        system("color 7");

        Container<Book>::iterator index = IndexBook();

        if(index != nullptr)
        {
            array[index].print();
            cout << "\n\t\t\t\t";
        }

        system("pause");
        system("cls");
    }

    void PrintBooksUnsorted()
    {
        system("cls");
        system("color 7");

        if (array.get_size() == 0)
        {
            cout << "\nNo Book In The Library." << endl;
        }
        else
        {
            cout << "\n\tExisting Books List:- " << endl;

            for (auto i = array.begin(); i !=  array.end(); i++)
            {
                array[i].print();
                cout << "-----------------" << endl;
            }
        }

        system("pause");
        system("cls");
    }

    void PrintBooksSorted()
    {
        system("cls");
        system("color 7");

        size_t size = array.get_size();

        if (size == 0)
        {
            cout << "\nNo Book In The Library." << endl;
        }
        else
        {

            int indexes[size];
            for (int i = 0; i < size; i++)
            {
                indexes[i] = i;
            }

            for (int i = 0; i < size - 1; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    if (array[i].title > array[j].title)
                    {
                        swap(indexes[i],indexes[j]);
                    }
                }
            }

            cout << "\n\tExisting Books List:- " << endl;
            for (int i = 0; i < size; i++)
            {
                array[indexes[i]].print();
                cout << "-----------------" << endl;
            }
        }


        system("pause");
        system("cls");
    }

    void BorrowBook()
    {
        system("cls");
        system("color 7");

        Container<Book>::iterator index = IndexBook();

        if(index != nullptr && array[index].available != 0)
        {
            array[index].available = 0;
            cout << "\n\t\t\t\tBook IS Borrowed\n\t\t\t\t";
        }

        else if (array[index].available == 0)
        {
            cout << "\t\t\t\tBook Is Already Booked!" << endl;
        }

        system("pause");
        system("cls");
    }

    void ReturnBook()
    {
        system("cls");
        system("color 7");

        Container<Book>::iterator index = IndexBook();

        if(index != nullptr && array[index].available != 1)
        {
            array[index].available = 1;
            cout << "\n\t\t\t\tBook Is Returned\n\t\t\t\t";
        }

        else if (array[index].available == 1)
        {
            cout << "\t\t\t\tBook Is Not Booked!" << endl;
        }

        system("pause");
        system("cls");
    }

    void BookStatistics()
    {
        system("cls");
        system("color 7");

        int BorrowedSum = 0;
        for(auto i = array.begin(); i != array.end(); i++)
            if(!array[i].available)
                BorrowedSum++;

        cout << "TOTAL NUMBER OF BOOKS IN THE LIBRARY IS -> " << array.get_size() << " Books" << endl;
        cout << "TOTAL NUMBER OF BORRORWED BOOKS IN THE LIBRARY IS -> " << BorrowedSum << " Books" << endl;
        cout << "TOTAL NUMBER OF AVAILABLE BOOKS IN THE LIBRARY IS -> " << (array.get_size() - BorrowedSum) << " Books" << endl;

        system("pause");
        system("cls");
    }

};

#endif // LIBRARYSYSTEM_H
