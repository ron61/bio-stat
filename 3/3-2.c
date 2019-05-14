/* 3-2.c */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",rand()%100+1);
    }
    
    return 0;
}