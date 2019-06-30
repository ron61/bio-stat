/* 03-190615 Ryu Kudoh */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#pragma region basics

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
int combination(int n,int m) {
    if(n < 0 || m < 0) {
        printf("error:invalid number in combination function");
        return 0;
    }

    if(n >= m) {
        return factorial(n) / ( factorial(m) * factorial(n - m) );
    }
    else {
        printf("error:first number is smaller than second one.");
        return 0;
    }
}

// 配列の中の1の数を数える関数
int countTrues(int x[],int k) {
    int n = 0;

    for (int i = 0; i < k; i++)
    {
        if (x[i] == 1) n++;
    }
    
    return n;
}

#pragma endregion

// 超幾何分布の関数
double hypergeom(int M,int N,int n,int k) {
    return (double)combination(M,k) * combination(N,n-k) / combination(M+N,n);
}


int main(void) {
    int x = 0;
    double m,v,hgm,hgv = 0;
    double f[2][11];    // この配列にベルヌーイ試行の結果と，超幾何分布による理論値を入れる
    int carp[20];    // 母集団の大きさ20
    int N=10;
    int M=10;
    int n=10;
    double p=0.5;

    // fの初期化
    for (int i = 0; i < 2; i++) for (int j = 0; j < 11; j++)   f[i][j] = 0;
    srand(time(0));    // 乱数のseedを仕込む
    
    for (int i = 0; i < 1000; i++)
    {
        // carpの初期化．全て0にする
        for (int i = 0; i < 20; i++)  carp[i] = 0;

        // 1が10個になるまでランダムに0と1を置き換えていく．1がメス，0がオスに相当する
        while(countTrues(carp,20)<10) {
            x = rand() % 20;
            carp[x] = 1;
        }
        // 長さ20の配列の前半にいるメスの数＝1の数を数える
        // 捕まえる鯉の場所は決まっていて（＝リストの前半分），
        // その中のどこにメスとオスが存在するかがランダムになっているということ．
        x = countTrues(carp,10);    
        f[0][x] ++;
    }

    // calculate mean
    for (int i = 0; i < 11; i++)
    {
        m += f[0][i] * i / 1000;
    }

    // calculate variance
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < f[0][i]; j++)
        {
            v += (i - m) * (i - m) / 1000;
        }
    }


    // calculate hyper geometry
    for (int i = 0; i <= 10; i++)
    {
        f[1][i] = hypergeom(N,M,n,i);
    }
 
    // calculate geometry mean
    hgm = n*p;

    // calculate geometry variance
    hgv = n * p * (1-p) * (M+N-n) / (M+N-1);
    

    printf("メスの数 ベルヌーイ試行 超幾何分布\n");

    for (int i = 0; i <= 10; i++)
    {
        printf("%3d\t%8.2lf\t%8.2lf\n",i,f[0][i],f[1][i]*1000);
    }

    printf("\n平均\t%8.2lf\t%8.2lf\n分散\t%8.2lf\t%8.2lf\n",m,hgm,v,hgv);

    return 0;
}
