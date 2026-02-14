#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

class Book {
public:

    void addBook() {
        ofstream file("library.txt", ios::app);

        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        file << id << "," << title << "," << author << ",Available" << endl;
        file.close();

        cout << "✅ Book Added Successfully!\n";
    }

    void viewBooks() {
        ifstream file("library.txt");
        string line;

        cout << "\n📚 --- Library Books ---\n";

        if (!file) {
            cout << "No records found.\n";
            return;
        }

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }

    void searchBook() {
        ifstream file("library.txt");

        int searchID;
        string line;
        bool found = false;

        cout << "Enter Book ID to search: ";
        cin >> searchID;

        while (getline(file, line)) {
            int id = stoi(line.substr(0, line.find(',')));

            if (id == searchID) {
                cout << "🔍 Book Found: " << line << endl;
                found = true;
                break;
            }
        }

        if (!found)
            cout << "❌ Book Not Found\n";

        file.close();
    }

    void issueBook() {
        ifstream file("library.txt");
        ofstream temp("temp.txt");

        int issueID;
        string line;
        bool found = false;

        cout << "Enter Book ID to issue: ";
        cin >> issueID;

       while (getline(file, line)) {

    if (line.empty()) continue;

    int commaPos = line.find(',');

    if (commaPos == string::npos) continue;

    string idStr = line.substr(0, commaPos);

    try {
        int id = stoi(idStr);

        if (id == issueID) {
            temp << id
                 << line.substr(line.find(','), line.rfind(',') - line.find(','))
                 << ",Issued\n";
            cout << "📕 Book Issued!\n";
            found = true;
        } else {
            temp << line << endl;
        }
    }
    catch (...) {
        temp << line << endl;
    }
}


        if (!found)
            cout << "❌ Book not found\n";

        file.close();
        temp.close();

        remove("library.txt");
        rename("temp.txt", "library.txt");
    }

    void returnBook() {
        ifstream file("library.txt");
        ofstream temp("temp.txt");

        int returnID;
        string line;
        bool found = false;

        cout << "Enter Book ID to return: ";
        cin >> returnID;

    while (getline(file, line)) {

    if (line.empty()) continue;

    int commaPos = line.find(',');

    if (commaPos == string::npos) continue;

    string idStr = line.substr(0, commaPos);

    try {
        int id = stoi(idStr);

        if (id == returnID) {
            temp << id
                 << line.substr(line.find(','), line.rfind(',') - line.find(','))
                 << ",Available\n";
            cout << "📗 Book Returned!\n";
            found = true;
        } else {
            temp << line << endl;
        }
    }
    catch (...) {
        temp << line << endl;
    }
}


        if (!found)
            cout << "❌ Book not found\n";

        file.close();
        temp.close();

        remove("library.txt");
        rename("temp.txt", "library.txt");
    }
};

int main() {

    Book book;
    int choice;

    while (true) {

        cout << "\n====== 📚 Library Management System ======\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {

            case 1: book.addBook(); break;
            case 2: book.viewBooks(); break;
            case 3: book.searchBook(); break;
            case 4: book.issueBook(); break;
            case 5: book.returnBook(); break;
            case 6:
                cout << "👋 Exiting...";
                return 0;

            default:
                cout << "❌ Invalid choice!";
        }
    }
}
