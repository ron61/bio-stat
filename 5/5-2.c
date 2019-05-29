/* 5-1.c */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


double sMean(int x[])
{
    double s = 0;
    double mean;
    int n = 10;
    for(int i = 0; i < n; i++)
    {
        s += x[i];
    }
    mean = s / n;
    return mean;
}

double sDispersion(int x[])
{
    int i;
    double m, disp;
    m = sMean(x);
    int n = 10;
    for(int i = 0; i < n; i++)
    {
        disp += (x[i] - m) * (x[i] - m) / (n-1);
    }
    
    return disp;
}

double sStandardDispersion(int x[]) {
    return sqrt(sDispersion(x));
}

int main(void)
{
    double m,v,s;
    int x[10];
    srand(time(0));

    for(int i = 0; i < 10; i++)
    {
        x[i] = 0;
        x[i] = rand()%6 + 1;
    }

    m = sMean(x);
    v = sDispersion(x);
    s = sStandardDispersion(x);

    printf("標本平均\t%8.2lf\n", m);
    printf("標本分散\t%8.2lf\n", v);
    printf("標本標準偏差\t%8.2lf\n", s);

    return 0;
    
}