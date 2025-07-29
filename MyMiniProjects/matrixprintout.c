#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int N, M;
    scanf("%d %d", &N, &M);

    int **matrix = malloc(N * sizeof(int));
    if (matrix == NULL){
        printf("Error in temp");
        return 1;
    }

    for(int i = 0; i < N; i++){
        matrix[i] = malloc(M * sizeof(int));
        if (matrix[i] == NULL){
            printf("Error in temp in the line");
            return 1;
        }
        for(int j = 0; j < i; j++){
            free(matrix[j]);
        }
        free(matrix);
        return 1;
    }

   
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            printf("elem %d %d ", i ,j);
            scanf("%d ", matrix[i][j]);
        }
    }

 
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    
   
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++){
        free(matrix[i]);
    }
    free(matrix);

}
