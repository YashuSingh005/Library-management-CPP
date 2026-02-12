#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    void addBook() {
        ofstream file("library.txt", ios::app);

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        file << id << "," << title << "," << author << endl;
        file.close();

        cout << "Book Added Successfully!\n";
    }

    void viewBooks() {
        ifstream file("library.txt");
        string line;

        cout << "\n--- Library Books ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }
};

int main() {
    Book book;
    int choice;

    do {
        cout << "\n====== Library Management ======\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                book.addBook();
                break;
            case 2:
                book.viewBooks();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}
