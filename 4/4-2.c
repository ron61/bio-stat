/* 4-2.c */
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

double geom(double p,int k) {
    return p * pow(1-p,k-1);
}

int main(void) {
    int x = 0;
    double m,v,gm,gv = 0;
    double f[2][500];
    double p = 0.5;
    // 初期化
    for (int i = 0; i < 2; i++) for (int j = 0; j < 500; j++) f[i][j] = 0;
    srand(time(0));
    
    for (int i = 0; i < 1000; i++)
    {
        x = 1;
        while(rand()%2) {
            x ++;
        }
        
        f[0][x] ++;
    }

    // calculate mean
    for (int i = 0; i < 1000; i++)
    {
        m += f[0][i] * i / 1000;
    }

    // calculate variance
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < f[0][i]; j++)
        {
            v += (i - m) * (i - m) / 1000;
        }
    }
    
    // calculate geometry
    for (int i = 1; i < 500; i++)
    {
        f[1][i] = geom(p,i) * 1000;
    }
 
    // calculate geometry mean
    gm = 1/p;

    // calculate geometry variance
    gv = (1-p)/(p*p);
    

    printf("成功回数 ベルヌーイ試行 幾何分布\n");

    for (int i = 1; i <= 20; i++)
    {
        printf("%3d\t%8.2lf\t%8.2lf\n",i,f[0][i],f[1][i]);
    }

    printf("\n平均\t%8.2lf\t%8.2lf\n分散\t%8.2lf\t%8.2lf\n",m,gm,v,gv);

    return 0;
}
