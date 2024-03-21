#include <stdio.h>
#include <stdlib.h>

#define N 8

int board[N][N];

int isSafe(int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;
    return 1;
}

int solveNQUtil(int col) {
    if (col >= N)
        return 1;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(col + 1))
                return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}

void printSolution() {
    static int k = 1;
    printf("%d-\n",k++);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

int solveNQ() {
    if (solveNQUtil(0) == 0) {
        printf("Solution does not exist!!");
        return 0;
    }

    printSolution();
    return 1;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    solveNQ();
    return 0;
}
