#include <stdio.h>

int main()
{
  int matrix[3][4];
  printf("Enter elements in a 3x4 matrix\n");
  for (int i=0;i<3;i++)
  {
    for (int j=0;j<4;j++)
    {
      printf("Enter element at position (%d, %d): ", i+1, j+1);
      scanf("%d", &matrix[i][j]);
    }
  }

  printf("\nThe matrix entered is:\n");
  for (int i=0;i<3;i++)
  {
    for (int j=0;j<4;j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}