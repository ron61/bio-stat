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
    for(int i = 0; i < n; i++) disp += (x[i] - m) * (x[i] - m) / (n-1);
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
    double population[25];
    double sample[10];
    double a,b,m,s,c;
    double me,se,ce;
    double dat[3][10000];
    //初期化
    for (int i = 0; i < 3; i++) for (int j = 0; j < 10000; j++) dat[i][j] = 0;
    
    
    // データの読み込み
    for(int i = 0; i < 25; i++)
    {
        population[i] = 0;
        scanf("%lf", &population[i]);
    }

    for (int j = 0; j < 10000; j++)
    {
        // 復元抽出によるサンプルの抽出
        for(int i = 0; i < 10;i++) {
            sample[i] = 0;
            sample[i] = population[rand()%25];
        }

        m = mean(10,sample);
        s = sDispersion(10,sample);
        c = sStandardDispersion(10,sample)*100/m;

        dat[0][j] = m;
        dat[1][j] = s;
        dat[2][j] = c;
        
    }

    m = mean(10000,dat[0]);
    s = mean(10000,dat[1]);
    c = mean(10000,dat[2]);
    
    me = sStandardDispersion(10000,dat[0]);
    se = sStandardDispersion(10000,dat[1]);
    ce = sStandardDispersion(10000,dat[2]);


    printf("母平均　%8.3lf\n", m);
    printf("母分散　%8.3lf\n", s);
    printf("母変動係数　%8.3lf\n\n", c);

    printf("標準誤差たち\n");
    printf("母平均　%8.3lf\n", me);
    printf("母分散　%8.3lf\n", se);
    printf("母変動係数　%8.3lf\n\n", ce);

    return 0;
    
}