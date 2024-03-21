#include <stdio.h>

int main(){
    int i=0, octal, decimal = 0, remainder;
    printf("Enter an Octal number:\n");
    scanf("%d", &octal);
    int og = octal;
    while(octal != 0){
        remainder = octal % 10;
        decimal += remainder * pow(8, i);
        i++;
        octal /=10;
    }

    printf("Octal no %d to decimal is %d", og, decimal);
    return 0;
}