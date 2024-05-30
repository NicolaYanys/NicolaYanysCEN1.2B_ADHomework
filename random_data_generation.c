#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "book_division.h"

// Function to generate random book pages and save to file
void generateAndSaveRandomBooks(int books[], int num_books) {
    srand(time(NULL));
    for (int i = 0; i < num_books; i++) {
        books[i] = rand() % 100000000 + 1; // Pages between 1 and 100000000
    }

    FILE *file = fopen("random_book_data.txt", "w");
    for (int i = 0; i < num_books; i++) {
        fprintf(file, "%d ", books[i]);
    }
    fclose(file);
}

void randomtestDataGeneration() {
    int num_books;
    int books[MAX_BOOKS];

    printf("Enter the number of books for random data generation: ");
    scanf("%d", &num_books);

    generateAndSaveRandomBooks(books, num_books);

    printf("Random book data has been generated and saved to random_book_data.txt\n");
}
