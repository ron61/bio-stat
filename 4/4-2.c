/* 4-1.c */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int factorial(int n) {
    if (n > 0)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}

int combination(int n,int m) {
    if(n < 0 || m < 0) {
        printf("error:invalid number in combinatino function");
        return 0;
    }

    if(n > m) {
        return factorial(n) / (factorial(m) * factorial(n - m));
    }
    else {
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
    x = combination(n,k) * p;
    return x;
}

int main(void) {
    int x = 0;
    double m,v = 0;
    double f[2][500];
    double b;
    // 初期化
    for (int i = 0; i < 2; i++) for (int j = 0; j < 500; j++) f[i][j] = 0;
    srand(time(0));
    
    for (int i = 0; i < 1000; i++)
    {
        x = 0;
        while(rand()%2) {
            x ++;
        }
        
        f[0][x] ++;
    }

    // calculate mean
    for (int i = 0; i < 1000; i++)
    {
        m += f[0][i] / 1000;
    }

    // calculate variance
    for (int i = 0; i < 500; i++)
    {
        v += (f[0][i] - m) * (f[0][i] - m) / 1000;
    }
    
    // calculate poisson
    for (int i = 0; i < 500; i++)
    {
        b = po(i,2.5);
        x = b * 1000;
        f[1][i] = x;
    }

    printf("成功回数\tベルヌーイ試行\tポアソン分布\n");

    for (int i = 0; i <= 15; i++)
    {
        printf("%3d\t%8.3lf\t%8.3lf\n",i,f[0][i],f[1][i]);
    }

    printf("\n平均:%8.3lf\n分散:%8.3lf\n",m,v);

    return 0;
}
