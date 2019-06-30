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
    m = mean(n,x);
    disp = 0;
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
    disp = 0;
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

int main(void) {
    srand(time(0));    // seedは現在時刻
    double height[11],weight[11];
    double a,b,h_mean,w_mean,h_s,w_s,h_e,w_e;
    double hm_f[2],hs_f[2],wm_f[2],ws_f[2];

    int n;
    scanf("%d", &n);
    
    // データの読み込み
    for(int i = 0; i < 11; i++) {
        weight[i] = 0;
        scanf("%lf", &weight[i]);
        height[i] = 0;
        scanf("%lf", &height[i]);
    }

    // 平均の信頼区間
    h_mean = mean(11,height);
    w_mean = mean(11,weight);
    h_s = standardDispersion(11,height);
    w_s = standardDispersion(11,weight);
    h_e = h_s / sqrt(11);
    w_e = w_s / sqrt(11);
    hm_f[0] = h_mean - 2.281 * h_e;
    hm_f[1] = h_mean + 2.281 * h_e;
    wm_f[0] = w_mean - 2.281 * w_e;
    wm_f[1] = w_mean + 2.281 * w_e;


    // 分散の信頼区間
    h_s = sDispersion(11,height);
    w_s = sDispersion(11,weight);
    hs_f[0] = 10 * h_s / 20.4832;
    hs_f[1] = 10 * h_s / 3.247;
    ws_f[0] = 10 * w_s / 20.4832;
    ws_f[1] = 10 * w_s / 3.247;
    

    printf("           身長　　　　　体重\n");
    printf("平均　　[%4.2lf,%4.2lf]    [%4.2lf,%4.2lf]\n", hm_f[0], hm_f[1],wm_f[0],wm_f[1]);
    printf("分散　　[%4.2lf,%4.2lf]    [%4.2lf,%4.2lf]\n", hs_f[0], hs_f[1],ws_f[0],ws_f[1]);

    return 0;
    
}