#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "book_division.h"

// Function to generate book pages and save to file
void generateAndSaveBooks(int books[], int num_books) {
    srand(time(NULL));
    int a = 100;
    for (int i = 0; i < num_books; i++) {
        books[i] = a;
        a += 100;
    }

    FILE *file = fopen("book_data.txt", "w");
    for (int i = 0; i < num_books; i++) {
        fprintf(file, "%d ", books[i]);
    }
    fclose(file);
}

void testDataGeneration() {
    int num_books;
    int books[MAX_BOOKS];

    printf("Enter the number of books for data generation: ");
    scanf("%d", &num_books);

    generateAndSaveBooks(books, num_books);

    printf("Book data has been generated and saved to book_data.txt\n");
}
