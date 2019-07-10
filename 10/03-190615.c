/* 03-190615 Ryu Kudoh */
/*
Newton法を用いた．
 */
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

double logL(double a, double b, double x[50], int y[50]) {
    double logL = 0;
    for (int i = 0; i < 50; i++)
    {
        logL += (double)y[i] * ( a + b * x[i]) - exp(a + b * x[i]);
    }

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < y[i]; j++)
        {
            logL += log(j);
        }
    }
    
    return logL;
}

void dLogL(double a, double b, double x[50], int y[50], double dlogL[2]) {
    dlogL[0] = 0;
    dlogL[1] = 0;
    for (int i = 0; i < 50; i++)
    {
        dlogL[0] += y[i] - exp(a + b * x[i]);
        dlogL[1] += x[i] * ( y[i] - exp(a + b * x[i]) );
    }
}

void dfInverse(double a, double b, double x[50], int y[50], double df_inverse[2][2]) {
    // k   : ヤコビ行列の係数の逆数 = ad - bc
    // tmp : 計算のための一時変数
    double k,tmp = 0;

    // kの計算開始
    for (int i = 0; i < 50; i++)
    {
        tmp += x[i] * x[i] * exp(a + b * x[i]);
    }

    k = tmp;
    tmp = 0;

    for (int i = 0; i < 50; i++)
    {
        tmp += exp(a + b * x[i]);
    }

    k *= tmp;
    tmp = 0;

    for (int i = 0; i < 50; i++)
    {
        tmp += x[i] * exp(a + b * x[i]);
    }

    k -= tmp * tmp;
    // kの計算終了

    // df_inverseの初期化
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            df_inverse[i][j] = 0;
        }
    }

    // df_inverseの係数以外の計算
    for (int i = 0; i < 50; i++)
    {
        df_inverse[0][0] -= x[i] * x[i] * exp(a + b * x[i]);
        df_inverse[0][1] += x[i] * exp(a + b * x[i]);
        df_inverse[1][0] += x[i] * exp(a + b * x[i]);
        df_inverse[1][1] -= exp(a + b * x[i]);
    }

    // df_inverseに係数をかける
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            df_inverse[i][j] /= k;
        }
    }
    
}

void matrixProduct(double A[2][2],double B[2], double product[2]) {
    product[0] = A[0][0] * B[0] + A[0][1] * B[1];
    product[1] = A[1][0] * B[0] + A[1][1] * B[1];
}

int main(void) {
    double x[50] = {};
    int y[50] = {};
    double df_inverse[2][2],product[2],dlogL[2] = {};
    double a,b = 0.01; // 初期値は収束するように定める必要がある
    int count = 0;

    // データの読み込み
    for(int i = 0; i < 50; i++) {
        scanf("%lf", &x[i]);
        scanf("%d", &y[i]);
    }

    while(1) {
        dfInverse(a,b,x,y,df_inverse);
        matrixProduct(df_inverse,dlogL,product);
        a -= product[0];
        b -= product[1];
        dLogL(a,b,x,y,dlogL);

        printf("%8.3lf \t %8.3lf\n",dlogL[0],dlogL[1]);
        
        // dlogLのL2ノルムがゼロに十分近づいたら終了する
        if(fabs(dlogL[0] * dlogL[0] + dlogL[1] * dlogL[1]) < 0.01) break;

        count  ++;
        if(count > 30) break;
    }


    printf("a : %lf\n",a);
    printf("b : %lf\n",b);
    printf("logL : %lf\n",logL(a,b,x,y));

    return 0;
}

