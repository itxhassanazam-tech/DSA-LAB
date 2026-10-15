#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
public:
    virtual void display() = 0;
    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;
public:
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }
    void display() override {
        cout << "Book: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
    int getPages() {
        return pages;
    }
    string getTitle() {
        return title;
    }
};

class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;
public:
    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }
    void display() override {
        cout << "Newspaper: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
    string getEdition() {
        return edition;
    }
    string getName() {
        return name;
    }
};

class Library {
private:
    Book* books[100];
    Newspaper* newspapers[100];
    int bookCount;
    int newspaperCount;
public:
    Library() {
        bookCount = 0;
        newspaperCount = 0;
    }
    void addBook(Book book) {
        books[bookCount] = new Book(book);
        bookCount++;
    }
    void addNewspaper(Newspaper newspaper) {
        newspapers[newspaperCount] = new Newspaper(newspaper);
        newspaperCount++;
    }
    void displayCollection() {
        cout << "\n--- Books ---" << endl;
        for (int i = 0; i < bookCount; i++) {
            books[i]->display();
            cout << endl;
        }
        cout << "--- Newspapers ---" << endl;
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i]->display();
            cout << endl;
        }
    }
    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < bookCount; j++) {
                if (books[j]->getPages() < books[minIndex]->getPages()) {
                    minIndex = j;
                }
            }
            Book* temp = books[i];
            books[i] = books[minIndex];
            books[minIndex] = temp;
        }
    }
    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < newspaperCount; j++) {
                if (newspapers[j]->getEdition() < newspapers[minIndex]->getEdition()) {
                    minIndex = j;
                }
            }
            Newspaper* temp = newspapers[i];
            newspapers[i] = newspapers[minIndex];
            newspapers[minIndex] = temp;
        }
    }
    Book* searchBookByTitle(string searchTitle) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getTitle() == searchTitle) {
                return books[i];
            }
        }
        return NULL;
    }
    Newspaper* searchNewspaperByName(string searchName) {
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i]->getName() == searchName) {
                return newspapers[i];
            }
        }
        return NULL;
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");
    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);
    cout << "Before Sorting:\n";
    library.displayCollection();
    library.sortBooksByPages();
    library.sortNewspapersByEdition();
    cout << "\nAfter Sorting:\n";
    library.displayCollection();
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook != NULL) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper != NULL) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }
    return 0;
}