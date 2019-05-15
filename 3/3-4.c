/* 3-2.c */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int klist[11] = {};
    int k,r;
    srand(time(0));
    for (int i = 0; i < 10000; i++)
    {
        k = 0;
        for (int j = 0; j < 10; j++)
        {
            r = rand()%2;
            if(r == 1) k++;
        } 

        klist[k] ++;
    }
    
    for (int i = 0; i < 11; i++)
    {
        printf("%d\n",klist[i]);
    }
    

    return 0;
}