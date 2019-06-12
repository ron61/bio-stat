/* 03-190615 Ryu Kudoh */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#pragma region basics
double mean(int n,double x[])
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
    m = mean(n,x);
    for(int i = 0; i < n; i++)
    {
        disp += (x[i] - m) * (x[i] - m) / (n-1);
    }
    
    return disp;
}

double dispersion(int n,double x[])
{
    int i;
    double m, disp;
    m = mean(n,x);
    for(int i = 0; i < n; i++)
    {
        disp += (x[i] - m) * (x[i] - m) / n;
    }
    
    return disp;
}

double sStandardDispersion(int n,double x[]) {
    return sqrt(sDispersion(n,x));
}

double standardDispersion(int n,double x[]){
    return sqrt(dispersion(n,x));
}

#pragma endregion

int main(void)
{
    double mean_of_means,mean_of_variances,mean_of_stddisps,variances_of_means;
    srand(time(0));    // seedは現在時刻
    double population[100];
    double sample[10];
    double a,b,m,s;

    int n;
    scanf("%d", &n);
    
    // データの読み込み
    for(int i = 0; i < 100; i++)
    {
        population[i] = 0;
        scanf("%lf", &population[i]);
    }

    // 復元抽出によるサンプルの抽出
    for(int i = 0; i < 10;i++) {
        sample[i] = 0;
        sample[i] = population[rand()%100];
    }

    m = mean(n,sample);
    s = standardDispersion(n,sample);

    a = m - 1.96 * s / sqrt(10);
    b = m + 1.96 * s / sqrt(10);

    printf("[%4.2lf,%4.2lf]\n", a, b);

    return 0;
    
}