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
    disp = 0;
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
    disp = 0;
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
    int m_number,s_number;
    m_number = 0;
    s_number = 0;
    double ma,mb,sa,sb;

    int n;
    scanf("%d", &n);
    
    // データの読み込み
    for(int i = 0; i < 100; i++)
    {
        population[i] = 0;
        scanf("%lf", &population[i]);
    }

    for (int j = 0; j < 1000; j++)
    {
        // 復元抽出によるサンプルの抽出
        for(int i = 0; i < 10;i++) {
            sample[i] = 0;
            sample[i] = population[rand()%100];
        }

        m = mean(n,sample);
        s = sStandardDispersion(n,sample);

        ma = m - 2.2281 * s / sqrt(10);
        mb = m + 2.2281 * s / sqrt(10);

        sa = 10 * sDispersion(n,sample) / 20.4832;
        sb = 10 * sDispersion(n,sample) / 3.247;

        if(ma < 4.55 && 4.55 < mb) m_number ++;
        if(sa < 0.152 && 0.152 < sb) s_number ++;
    }
    
    
    printf("平均の回数　%d\n", m_number);
    printf("分散の回数　%d\n", s_number);

    return 0;
    
}