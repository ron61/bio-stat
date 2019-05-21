/* 3-3.c */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){

    double x[100];
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }

    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        printf("%3.1f\n",x[rand()%100]);
    }
    
    return 0;
}