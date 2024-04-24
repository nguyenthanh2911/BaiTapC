#include <stdio.h>

// Recursive function to calculate compound interest
float lai_kep(float y, int n, float x) {
    if (n == 0)
        return y;
    return lai_kep(y, n - 1, x) * (1 + x / 100);
}

int main() {
    float y; // Initial amount
    int n; // Number of years
    float x; // Fixed interest rate

    printf("Enter the initial amount (y): ");
    scanf("%f", &y);
    printf("Enter the number of years (n): ");
    scanf("%d", &n);
    printf("Enter the fixed interest rate (x): ");
    scanf("%f", &x);

    float final_amount = lai_kep(y, n, x);
    printf("Final amount after %d years: %.2f\n", n, final_amount);

    return 0;
}

