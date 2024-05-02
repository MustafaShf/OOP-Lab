#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;

class Book {
private:
    string title;
    string author;
    int publicationYear;

public:
    Book() : title(""), author(""), publicationYear(0) {}

    Book(const string& title, const string& author, int year) : title(title), author(author), publicationYear(year) {}

    void setDetails(const string& title, const string& author, int year) {
        this->title = title;
        this->author = author;
        this->publicationYear = year;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getPublicationYear() const {
        return publicationYear;
    }

    void displayBook() const {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << publicationYear << endl;
    }
};

class Library {
private:
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library() : bookCount(0) {}

    bool addBook(const Book& book) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount++] = book;
            return true;
        }
        return false;
    }

    void displayAllBooks() const {
        for (int i = 0; i < bookCount; i++) {
            books[i].displayBook();
        }
    }

    void searchByTitle(const string& title) const {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                books[i].displayBook();
                found = true;
            }
        }
        if (!found) {
            cout << "No books found with the title \"" << title << "\"." << endl;
        }
    }

    void searchByAuthor(const string& author) const {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getAuthor() == author) {

                books[i].displayBook();
                found = true;
            }
        }
        if (!found) {
            cout << "No books found by the author \"" << author << "\"." << endl;
        }
    }
};

int main() {
    Library library;
    library.addBook(Book("Subtle art of not giving a F*ck", "harry", 1949));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));

    cout << "All books in the library:" << endl;
    library.displayAllBooks();

    cout << "\nSearching for books by harry:" << endl;
    library.searchByAuthor("harry");

    cout << "\nSearching for 'The Great Gatsby':" << endl;
    library.searchByTitle("The Great Gatsby");

    return 0;
}
