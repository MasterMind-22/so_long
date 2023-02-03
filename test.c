#include<stdio.h>

int main()
{
    for (int i=0;i<10;i++)
        for (int j=0;j<10-i;j++)
        {
            if (i==0 || j==0 || i==9 || j==9)
                printf("\n");
            printf("#");
        }
}