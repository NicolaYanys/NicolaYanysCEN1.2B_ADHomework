#include <stdio.h>
#include <stdlib.h>
#include "book_division.h"

void testDataGeneration();
void randomtestDataGeneration();

int main() {
    int num_employees, num_books;

    FILE *input_file = fopen("input_data.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fscanf(input_file, "%d", &num_employees);
    fscanf(input_file, "%d", &num_books);

    int *books = (int *)malloc(num_books * sizeof(int));
    for (int i = 0; i < num_books; i++) {
        fscanf(input_file, "%d", &books[i]);
    }
    fclose(input_file);

    divideBooksAmongEmployees(books, num_books, num_employees);

    free(books);

    // Uncomment these lines to generate data for testing
    // testDataGeneration();
    // randomtestDataGeneration();


    return 0;
}
