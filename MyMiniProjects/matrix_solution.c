#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n = 100; 
    FILE *file = fopen("input.txt", "r");
    if (!file){
        printf("Error while opening");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
    
    int squares = 0;
    int circles = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (matrix[i][j] == 1 && 
                matrix[i][j+1] == 1 && 
                matrix[i+1][j] == 1 && 
                matrix[i+1][j+1] == 1) {
                squares++;
            }
            else if (matrix[i][j] == 1 && 
                     matrix[i+1][j+1] == 1 && 
                     matrix[i][j+1] == 0 && 
                     matrix[i+1][j] == 0) {
                circles++;
            }
        }
    }
    
    printf("%d %d\n", squares, circles);
    return 0;
}