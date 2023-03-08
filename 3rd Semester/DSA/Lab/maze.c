#include <stdio.h>
#include <stdlib.h>

int visited[50][50], count = 0;

void findPaths(int maze[50][50], int row, int col, int size) {
    if (row == size - 1 && col == size - 1) {
        count++;
        visited[row][col] = 1;
        printf("\nSolution %d \n", count);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%d ", visited[i][j]);
            }
            printf("\n");
        }
        visited[row][col] = 0;
        return;
    } else {
        visited[row][col] = 1;
    }
    if (row + 1 < size && visited[row + 1][col] == 0 &&
        maze[row + 1][col] == 1) {
        findPaths(maze, row + 1, col, size);
    }
    if (col + 1 < size && visited[row][col + 1] == 0 &&
        maze[row][col + 1] == 1) {
        findPaths(maze, row, col + 1, size);
    }
    if (row - 1 >= 0 && visited[row - 1][col] == 0 && maze[row - 1][col] == 1) {
        findPaths(maze, row - 1, col, size);
    }
    if (col - 1 >= 0 && visited[row][col - 1] == 0 && maze[row][col - 1] == 1) {
        findPaths(maze, row, col - 1, size);
    }
    visited[row][col] = 0;
}

void main() {
    int size;
    printf("Enter size of the maze: ");
    scanf("%d", &size);
    int maze[50][50];
    printf("Enter the maze (1->open && 0->close): \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    printf("Enter the starting block (row, col): ");
    int row, col;
    scanf("%d%d", &row, &col);
    if (maze[row][col] == 0) {
        printf("Rat is blocked \n");
        return;
    }
    findPaths(maze, row, col, size);
    if (count == 0) {
        printf("No paths found \n");
    }
}
