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

#pragma endregion

int main(void)
{
    double mean_of_means,mean_of_variances,mean_of_stddisps,variances_of_means;
    srand(time(0));    // seedは現在時刻
    double population[100];
    double sample[10];
    double means[1000];
    double variances[1000];
    double standarddisps[1000];
    // 配列の初期化
    for(int i = 0;i < 1000; i++) {
        means[i] = 0;
        variances[i] = 0;
        standarddisps[i] = 0;
    }
    int i,n;
    scanf("%d", &n);
    
    // データの読み込み
    for(int i = 0; i < 100; i++)
    {
        population[i] = 0;
        scanf("%lf", &population[i]);
    }

    for (int i = 0; i < 1000; i++)
    {
        // 復元抽出によるサンプルの抽出
        for(int i = 0; i < 10;i++) {
            sample[i] = 0;
            sample[i] = population[rand()%100];
        }

        means[i] = mean(10,sample);
        variances[i] = sDispersion(10,sample);
        standarddisps[i] = sStandardDispersion(10,sample);
    }

    mean_of_means = mean(1000,means);
    mean_of_variances = mean(1000,variances);
    mean_of_stddisps = mean(1000,standarddisps);
    variances_of_means = dispersion(1000,means); 

    printf("mean_of_means\t\t%8.3lf\n", mean_of_means);
    printf("mean_of_variances\t%8.3lf\n", mean_of_variances);
    printf("mean_of_stddisps\t%8.3lf\n", mean_of_stddisps);
    printf("variances_of_means\t%8.3lf\n", variances_of_means);

    return 0;
    
}