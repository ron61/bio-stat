/* 03-190615 工藤龍 */
#include<stdio.h>

int main(void){
    double x;
    double s = 0;
    for(int i = 0; i<8;i++){
        scanf("%lf", &x);
        s = s + x;
    }
    printf("%f", s);
    return 0;
    
}