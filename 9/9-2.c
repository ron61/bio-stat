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
    double bean[5][10],m[5] = {};
    double b,s,t,f,m1,m2,v1,v2,v,M = 0;
    int n1,n2,a,n,va,ve,vt = 0;
    double st,se,sa,msa,mse,F = 0;

    // データの読み込み
    scanf("%d", &a);
    scanf("%d", &n);
    for(int i = 0; i < a; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bean[i][j] = 0;
            scanf("%lf", &bean[i][j]);
        }
    }

    for (int i = 0; i < a; i++)
    {
        m[i] = 0;
        m[i] = mean(n,bean[i]);
    }

    M = mean(a,m);
    
    // stを求める
    st = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < n; j++)
        {
            st += (bean[i][j] - M) * (bean[i][j] - M);
        }
    }

    // seを求める
    se = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < n; j++)
        {
            se += (bean[i][j] - m[i]) * (bean[i][j] - m[i]);
        }
    }

    va = a-1;
    ve = a * (n-1);
    vt = a * n -1;

    sa = st - se;
    msa = sa / va;
    mse = se/ ve;
    F = msa / mse;
    

    printf("va：%2d  sa：%8.3lf  msa：%8.3lf  F：%8.3lf\n", va,sa,msa,F);
    printf("ve：%2d  se：%8.3lf  mse：%8.3lf\n", ve,se,mse);
    printf("vt：%2d  st：%8.3lf\n", vt,st);

    return 0;
}
