#include "book_division.h"
#include <stdio.h>
#include <limits.h>

int isFeasible(int books[], int x, int y, int m) {
    int requiredEmployees = 1;
    int currentLoad = 0;

    for (int i = 0; i < x; i++) {
        if (books[i] > m) {
            return 0;
        }
        if (currentLoad + books[i] > m) {
            requiredEmployees++;
            currentLoad = books[i];
            if (requiredEmployees > y) {
                return 0;
            }
        } else {
            currentLoad += books[i];
        }
    }
    return 1;
}

int findOptimalWorkload(int books[], int x, int y) {
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += books[i];
    }

    int left = 0;
    int right = sum;
    int result = INT_MAX;

    while (left <= right) {
        int m = (left + right) / 2;
        if (isFeasible(books, x, y, m)) {
            result = m;
            right = m - 1;
        } else {
            left = m + 1;
        }
    }

    return result;
}

void divideBooksAmongEmployees(int books[], int num_books, int num_employees) {
    int optimalWorkload = findOptimalWorkload(books, num_books, num_employees);
    FILE *output_file = fopen("output_data.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return;
    }
    fprintf(output_file, "The optimal division of books to minimize the maximum workload is:\n");

    int currentLoad = 0;
    int currentEmployee = 1;
    int startIdx = 0;

    for (int i = 0; i < num_books; i++) {
        if (currentLoad + books[i] > optimalWorkload) {
            fprintf(output_file, "Employee %d: %d pages ( ", currentEmployee, currentLoad);
            for (int j = startIdx; j < i; j++) {
                fprintf(output_file, "%d ", books[j]);
            }
            fprintf(output_file, ")\n");

            currentLoad = books[i];
            currentEmployee++;
            startIdx = i;
        } else {
            currentLoad += books[i];
        }

        if (i == num_books - 1) {
            fprintf(output_file, "Employee %d: %d pages ( ", currentEmployee, currentLoad);
            for (int j = startIdx; j <= i; j++) {
                fprintf(output_file, "%d ", books[j]);
            }
            fprintf(output_file, ")\n");
        }
    }

    fprintf(output_file, "The optimal division of books to minimize the maximum workload is: %d pages\n", optimalWorkload);
    fclose(output_file);
}
