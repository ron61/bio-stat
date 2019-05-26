#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(void)
{
	double x;
	int n = 10, i, k;
	
	for (k = 0;k < n;k++) {
		x = 1;

		for (i = 0; i < k;i++) {
			x = x * (n - i) / (k - i);
		}
		
		x = x * pow(1/2, n);
		printf("%2d\t%8.3f\n", k, 1000 * x);
	}
	return 0;
}
