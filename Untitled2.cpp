#include <stdio.h>


float lai_kep(float y, int n, float x) {
    if (n == 0)
        return y;
    return lai_kep(y, n - 1, x) * (1 + x / 100);
}

int main() {
    float y; 
    int n; 
    float x; 

    printf("nhap tien (y): ");
    scanf("%f", &y);
    printf("nam (n): ");
    scanf("%d", &n);
    printf("lai suat (x): ");
    scanf("%f", &x);

    float final_amount = lai_kep(y, n, x);
    printf("so tien sau  %d nam: %.2f\n", n, final_amount);

    return 0;
}

