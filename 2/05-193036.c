/* 05-193036 針尾紗彩 */
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

double disp(int n, double x[])
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

double sd(int n, double x[])
{
    double devi;
    devi = sqrt(disp(n, x));

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

double coefficient_of_determination(int n, double x[], double y[])
{
    double r, r2;
    r = covariance(n, x, y) / (sd(n, x) * sd(n, y));
    r2 = r * r;
    return r2;
}

int main(void)
{
    double a,b;
    int i,n;

    scanf("%d", &n);

    double x[n], y[n];

    for(int i = 0; i < n; i++)
    {

        scanf("%lf", &x[i]);
        scanf("%lf", &y[i]);
    }

    b = covariance(n, x, y) / disp(n, x);

    a = mean(n, y) - b * mean(n, x);

    printf("決定係数＝ %6.3f\n", coefficient_of_determination(n, x, y));
    printf("回帰方程式　 y = %6.3f + %6.3f  x \n", a, b);

    return 0;
    
}