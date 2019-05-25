/* hypergeo.c */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#pragma region basics
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

int countTrues(int x[],int k) {
    int n = 0;

    for (int i = 0; i < k; i++)
    {
        if (x[i] == 1) n++;
    }
    
    return n;
}
#pragma endregion

#pragma region models
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

double hypergeom(int M,int N,int n,int k) {
    return combination(M,k) * combination(N,n-k) / combination(M+N,k);
}
#pragma endregion 


int main(void) {
    int x = 0;
    double m,v,hgm,hgv = 0;
    double f[2][11];
    int carp[20];
    int N=10;   int M=10;   int n = 10;
    double p = 0;
    p = M / (M+N);

    // 初期化
    for (int i = 0; i < 2; i++) for (int j = 0; j < 11; j++)   f[i][j] = 0;
    for (int i = 0; i < sizeof(carp); i++)  carp[i] = 0;
    srand(time(0));
    
    for (int i = 0; i < 1000; i++)
    {
        while(countTrues(carp,sizeof(carp))<10) {
            x = rand() % 20;
            carp[x] = 1;
        }
    
        f[0][countTrues(carp,sizeof(carp)/2)] ++;
    }

    /*
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
    */
    

    // calculate geometry
    for (int i = 0; i <= 10; i++)
    {
        f[1][i] = hypergeom(M,N,n,i) * 1000;
    }
 
    // calculate geometry mean
    hgm = n*p;

    // calculate geometry variance
    hgv = n * p * (1-p) * (M+N-n) / (M+N-1);
    

    printf("成功回数 ベルヌーイ試行 超幾何分布\n");

    for (int i = 1; i <= 20; i++)
    {
        printf("%3d\t%8.2lf\t%8.2lf\n",i,f[0][i],f[1][i]);
    }

    printf("\n平均\t%8.2lf\t%8.2lf\n分散\t%8.2lf\t%8.2lf\n",m,hgm,v,hgv);

    return 0;
}
