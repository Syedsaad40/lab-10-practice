#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
};

int main() {
    struct Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald"};
    printf("Book: %s by %s\n", book1.title, book1.author);
    return 0;
}
