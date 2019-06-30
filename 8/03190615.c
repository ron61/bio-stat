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

#pragma region distributions

// 整数の階乗を計算する関数
long int factorial(int n) {
    if (n > 0)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}

// combinationを計算する関数
double combination(int n,int m) {
    double x = 1;
    if(n < 0 || m < 0) {
        printf("error:invalid number in combination function");
        return 0;
    }

    if(n >= m) {
        for (int i = 0; i < m; i++)
        {
            x *= n - i;
        }
        for (int i = 0; i < m; i++)
        {
            x /= m - i;
        }
        
        return x;
    }
    else {
        printf("error:first number is smaller than second one.");
        return 0;
    }
}

double po(int k,double l) {
    double x;
    x = pow(l,k) / (factorial(k) * exp(l));
    return x;
}

double ber(double s,int k,int n) {
    double p = pow(s,k) * pow(s,n-k);
    double x = 0;
    x = (double)combination(n,k) * p;
    return x;
}

double geom(double p,int k) {
    return p * pow(1-p,k-1);
}

#pragma endregion

int main(void)
{
    double mouse[2][20];
    double a,b,m,s,t,f,m1,m2,v1,v2,v;
    int n1,n2;

    // データの読み込み
    scanf("%d", &n1);
    for(int i = 0; i < n1; i++)
    {
        mouse[0][i] = 0;
        scanf("%lf", &mouse[0][i]);
    }
    scanf("%d", &n2);
    for(int i = 0; i < n2; i++)
    {
        mouse[1][i] = 0;
        scanf("%lf", &mouse[1][i]);
    }

    v = ((n1 - 1)*sDispersion(n1,mouse[0]) + (n2 - 1)*sDispersion(n2,mouse[1])) / (n1 + n2 -2);
    t = (mean(n1,mouse[0]) - mean(n2,mouse[1])) / sqrt((1/(double)n1 + 1/(double)n2) * v);
    f = sDispersion(n1,mouse[0]) / sDispersion(n2,mouse[1]);
    
    printf("\nt検定量：%lf    自由度：%d\n", t,n1+n2-2);
    printf("F検定量：%lf    自由度：%d\n\n", f, n1-1);

    printf("size1：%d\n", n1);
    printf("mean1：%lf\n", mean(n1,mouse[0]));
    printf("variance1：%lf\n", sDispersion(n1,mouse[0]));
    printf("sd1：%lf\n\n", sStandardDispersion(n1,mouse[0]));
    
    printf("size2：%d\n", n2);
    printf("mean2：%lf\n", mean(n2,mouse[1]));
    printf("variance2：%lf\n", sDispersion(n2,mouse[1]));
    printf("sd2：%lf\n", sStandardDispersion(n2,mouse[1]));

    return 0;
}
