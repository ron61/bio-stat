/* 03-190615 工藤龍 */
#include<stdio.h>
#include<math.h>

double mean(int n, double x[])
{
    int i;
    double s, mean;
    s = 0;
    for(int i = 0; i < n; i++)
    {
        s += x[i];
    }
    mean = s / n;
    return mean;
}

double dispersion(int n, double x[])
{
    int i;
    double m, disp;
    m = mean(n, x);
    for(int i = 0; i < n; i++)
    {
        disp += (x[i] - m) * (x[i] - m) / n;
    }
    
    return disp;
}

double standard_deviation(int n, double x[])
{
    double devi;
    devi = sqrt(dispersion(n, x));

    return devi;
}

double covariance(int n, double x[], double y[])
{
    double cov, mx, my;
    cov = 0;
    mx = mean(n, x);
    my = mean(n, y);
    for(int i = 0; i < n; i++)
    {
        cov += (x[i] - mx) * (y[i] - my) / n;
    }

    return cov;
}

double correlation_coefficient(int n, double x[], double y[])
{
    double cc;
    cc = covariance(n, x, y) / (standard_deviation(n, x) * standard_deviation(n, y));
    return cc;
}

double coefficient_of_determination(int n, double x[], double y[])
{
    double r, r2;
    r = covariance(n, x, y) / (standard_deviation(n, x) * standard_deviation(n, y));
    r2 = r * r;
    return r2;
}

int main(void)
{
    double x[100];
    int i,n;
    scanf("%d", &n);
    
    for(int i = 0; i < 100; i++)
    {
        scanf("%lf", &x[i]);
    }

    printf("mean = %6.3f\n", mean(n, x));
    printf("dispersion = %6.3f\n", dispersion(n, x));
    printf("standard_deviation = %6.3f\n", standard_deviation(n, x));

    return 0;
    
}