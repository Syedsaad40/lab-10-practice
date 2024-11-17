#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
    char ISBN[13];
    int publicationYear;
    int isAvailable;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook(char* title, char* author, char* ISBN, int publicationYear, int isAvailable) {
    if (bookCount < MAX_BOOKS) {
        strcpy(library[bookCount].title, title);
        strcpy(library[bookCount].author, author);
        strcpy(library[bookCount].ISBN, ISBN);
        library[bookCount].publicationYear = publicationYear;
        library[bookCount].isAvailable = isAvailable;
        bookCount++;
    } else {
        printf("Library is full.\n");
    }
}

void searchBook(char* query) {
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, query) || strstr(library[i].author, query)) {
            printf("Title: %s\nAuthor: %s\nISBN: %s\nYear: %d\nAvailable: %s\n",
                   library[i].title, library[i].author, library[i].ISBN,
                   library[i].publicationYear,
                   library[i].isAvailable ? "Yes" : "No");
        }
    }
}

void updateAvailability(char* ISBN, int isAvailable) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].ISBN, ISBN) == 0) {
            library[i].isAvailable = isAvailable;
            printf("Book availability updated.\n");
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    addBook("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", 1925, 1);
    addBook("To Kill a Mockingbird", "Harper Lee", "9780061120084", 1960, 1);
    searchBook("F. Scott Fitzgerald");
    updateAvailability("9780743273565", 0);
    return 0;
}
