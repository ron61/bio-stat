/* 5-1.c */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


double sMean(int n,double x[])
{
    double s = 0;
    double mean;
    for(int i = 0; i < n; i++)
    {
        s += x[i];
    }
    mean = s / n;
    return mean;
}

double sDispersion(int n,double x[])
{
    int i;
    double m, disp;
    m = sMean(n,x);
    for(int i = 0; i < n; i++)
    {
        disp += (x[i] - m) * (x[i] - m) / (n-1);
    }
    
    return disp;
}

double sStandardDispersion(int n,double x[]) {
    return sqrt(sDispersion(n,x));
}

int main(void)
{
    double m,v,s;
    srand(615);    // seedは学生証番号の下四桁
    double population[100];
    double sample[10];
    int i,n;
    scanf("%d", &n);
    
    for(int i = 0; i < 100; i++)
    {
        scanf("%lf", &population[i]);
    }

    for(int i = 0; i < 10;i++) {
        sample[i] = population[rand()%100];
    }

    n = 10;
    m = sMean(n,sample);
    v = sDispersion(n,sample);
    s = sStandardDispersion(n,sample);

    printf("標本平均\t%8.2lf\n", m);
    printf("標本分散\t%8.2lf\n", v);
    printf("標本標準偏差\t%8.2lf\n", s);

    return 0;
    
}