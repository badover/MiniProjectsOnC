#include <stdio.h>
#include <stdlib.h.>
#include <string.h>
#include <stdbool.h>

#define MAX_N 10

typedef struct{
    int x, y;
}Point;

int n = 0;
int matrix[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int components_size;
int minX, maxX, minY, maxY;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

bool is_valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y<n;
}

void dfs(int x, int y){
    Point stack[MAX_N * MAX_N];
    int top = -1;

    stack[++top] = (Point){x,y};
    visited[x][y] = true;

    while (top > 0){
        Point p = stack[top--];
        int x = p.x, y=p.y;
        components_size++;

        if(x < minX) minX = x;
        if(x > maxX) maxX = x;
        if(y < minY) minY = y;
        if(y > maxY) maxY = y;

        for (int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_valid(nx, ny) && matrix[nx][ny] == 1 && !visited[nx][ny]){
                stack[++top] = (Point){nx, ny};
                visited[nx][ny] = true;
            }
        }
    }
}

bool is_square(int minX, int maxX, int minY, int maxY, int size){
    int height = maxX - minX + 1;
    int width = maxY - minY + 1;
    return height == width && height * width == size;
}


int main(){

    FILE *file = fopen("input.txt", "r");
    if(!file){
        printf("Error while opening");
        return 1;
    }

    char line [MAX_N * 2];
    n = 0;
    while(fgets(line, sizeof(line), file)){
        int m = 0;
        char *token = strtok(line, " "); // '1' - string
        while (token){
            matrix[n][m++] = atoi(token);
            token = strtok(NULL, " ");
        }
        n++;
    }
    fclose(file);

    memset(visited, false, sizeof(visited));
    int squares = 0, circles = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (matrix[i][j] == 1 && !visited[i][j]){
                minX = maxX = i;
                minY = maxY = j;
                components_size = 0;
                dfs(i, j);
                
            
                if(components_size > 1){
                    if (is_square(minX, maxX, minY, maxY, components_size)){
                    squares++;
                }else{
                    circles++;
                }
                
            }
            }
            
        }
    }

    printf("squares: %d \n Circles: %d\n", squares, circles);

    return 0;
}