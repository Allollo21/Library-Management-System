#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string title;
    string author;
    string isbn;
    string genre;
    bool available;

    Book(): title("Unknown"), author("Unknown"), isbn("Unknown"), genre("Unknown"), available(1) {}

    void read()
    {
        cout << "Enter The Title Of The Book:  ";
        getline(cin >> ws, title);
        cout << "Enter The Author Of The Book:  ";
        getline(cin >> ws, author);
        cout << "Enter The ISBN Of The Book:  ";
        getline(cin >> ws, isbn);
        cout << "Enter The Genre Of The Book:  ";
        getline(cin >> ws, genre);
    }

    void print()
    {
        cout << "Title -> " << title << endl;
        cout << "Author -> " << author << endl;
        cout << "ISBN -> " << isbn << endl;
        cout << "Genre -> " << genre << endl;

        if(available == true)
            cout << "Availability -> Available" << endl;
        else
            cout << "Availability -> Not Available" << endl;
    }


    bool operator==(const Book& other) const
    {
        return title == other.title && author == other.author && isbn == other.isbn && genre == other.genre && available == other.available;
    }

    void operator= (const Book& other)
    {
        title = other.title;
        author = other.author;
        isbn = other.isbn;
        genre = other.genre;
    }
};

#endif // BOOK_H
