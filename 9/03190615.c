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
    double kasagai[2][3][8],m[2][3] = {};
    double s,t,f,m1,m2,v1,v2,v,M = 0;
    int n1,n2,a,n,b = 0;
    double st,se,sa,sb,sab,msa,msb,msab,mse,Fa,Fb,Fab = 0;

    // カサガイデータの読み込み
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &n);
    for(int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            for (int k = 0; k < n; k++)
            {
                scanf("%lf", &kasagai[i][j][k]);
            }
        }
    }

    // mijの計算
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            m[i][j] = mean(n,kasagai[i][j]);
        }
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


    sa = st - se;
    msa = sa / (a-1);
    msb = sb / (b-1);
    msab = sab / ((a-1) * (b-1));
    mse = se / (a * b * (n-1));
    Fa = msa / mse;
    Fb = msb / mse;
    Fab = msab / mse;
    

    printf("要因    自由度    平方和       平均平方    F値");
    printf("A       %2d     %8.3lf      %8.3lf     %8.3lf\n", a-1,sa,msa,Fa);
    printf("B       %2d     %8.3lf      %8.3lf     %8.3lf\n", b-1,sb,msb,Fb);
    printf("A*B     %2d     %8.3lf      %8.3lf     %8.3lf\n", (a-1)*(b-1),sab,msab,Fab);
    printf("誤差     %2d     %8.3lf      %8.3lf\n", a * b * (n-1),se,mse);
    printf("合計     %2d     %8.3lf\n", a * b * n -1,st);

    return 0;
}
