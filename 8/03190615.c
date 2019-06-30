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

int intSum(int n,int x[]) {
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        m += x[i];
    }
    return m;
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
    double k2;
    int n,fi,fj,r,c,mite[5][2];
    n = 0;
    k2 = 0;
    fi = 0;
    fj = 0;
    r = 0;
    c = 0;

    // データの読み込み
    scanf("%d", &r);
    scanf("%d", &c);
    for(int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mite[i][j] = 0;
            scanf("%d", &mite[i][j]);
            // nの計算
            n += mite[i][j];
        }
    }


    for (int i = 0; i < r; i++)
    {
        fi = mite[i][0] + mite[i][1];
        
        for (int j = 0; j < c; j++)
        {
            fj = 0;

            for (int k = 0; k < r; k++)
            {
                fj += mite[k][j];
            }
            
            k2 += (mite[i][j] - fi * fj / n) * (mite[i][j] - fi * fj / n) / (fi * fj / n);
        }
    }

    printf("k2検定量：%lf\n", k2);
    printf("自由度：%d\n", 4);

    return 0;
}

/*
このプログラムを実行すると，出力結果は以下のようになる．
｀｀｀
k2検定量：26.000
自由度：4
｀｀｀
一方，カイ二乗分布表を見ると，
*/
