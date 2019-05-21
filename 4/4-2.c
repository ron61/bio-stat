/* 4-2.c */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int factorial(int n) {
    if (n > 0)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}

double ber_05(int k,int n) {
    double p = pow(0.5,10);
    double x = 0;
    x = (factorial(n) * p) / (factorial(k)*factorial(n-k));
    return x;
}

int main(void) {
    int x = 0;
    double b;
    for (int i = 0; i < 11; i++)
    {
        b = ber_05(i,10);
        x = b * 1000;
        printf("%d :%d\n",i,x);
    }

    return 0;
}
