#include <stdio.h>

#define MAX_SIZE 10
void matrixMultiplication(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows1, int cols1, int rows2, int cols2)
{

  if (cols1 != rows2)
  {
    printf("Error! Can not mulitiply the two matrices\n");
    return;
  }

  for (int i=0;i<rows1;i++)
  {
    for (int j=0;j<cols2;j++)
    {
      result[i][j] = 0;
      for (int k=0;k<cols1;k++)
      {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}

void displayMatrix(int mat[][MAX_SIZE], int rows, int cols)
{
  for (int i=0;i<rows;i++)
  {
    for (int j=0;j<cols;j++)
    {
      printf("%d\t", mat[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
  int rows1, cols1, rows2, cols2;
  printf("Enter rows and columns for first matix:\n");
  scanf("%d %d", &rows1, &cols1);
  printf("Enter elements for the second matrix:\n");
  for (int i=0;i<rows1;i++)
  {
    for (int j=0;j<cols1;j++)
    {
      scanf("%d", &matrix1[i][j]);
    }
  }

  printf("Enter rows and columns for second matix:");
  scanf("%d %d", &rows2, &cols2);
  printf("Enter elements of the second matrix:\n");
  for (int i=0;i<rows2;i++)
  {
    for (int j=0;j<cols2;j++)
    {
      scanf("%d", &matrix2[i][j]);
    }
  }

  matrixMultiplication(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
  printf("Multiplication is:\n");
  displayMatrix(result, rows1, cols2);
  return 0;
}