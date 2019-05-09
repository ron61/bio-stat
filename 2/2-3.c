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
    int i,n;
    scanf("%d", &n);
    double x[n], y[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
        scanf("%lf", &y[i]);
    }

    printf("covariance = %6.5f\n", covariance(n, x, y));
    printf("correlation_coefficient = %6.5f\n", correlation_coefficient(n, x, y));

    return 0;
    
}