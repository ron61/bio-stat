/* 03190615 Kudoh Ryu */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double ber_05(int k,int n)
{
    double x = 0;
    double r = 1;

    for (int i = 0; i < k; i++)
    {
        r = r*(n/k);
        n --;
        k --;
    }

    x = r * pow(0.5,10);
    return x;
}

int main(void)
{
    int x;
    for (int i = 0; i < 11; i++)
    {
        x = ber_05(i,10)*1000;
        printf("%d : %d\n",i,x);
    }

    return 0;
}