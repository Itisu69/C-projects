#include <stdio.h>

int main(void)
{
    int n,x,y;

    printf("Enter an integer number: \n");
    scanf("%d",&n);

    printf("The reverse is :");
    do {
        x = n%10;
        printf("%d",x);
        n/=10;
    }while(n!=0);
    
    
        return 0;
}