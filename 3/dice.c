/* dice.c */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
    srand(time(0));
    printf("%d\n",rand()%6+1);
    return 0;
}