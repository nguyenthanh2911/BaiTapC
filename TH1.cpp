#include <stdio.h>


double capsocong(int n, int a, int r) {
    if (n == 1)
        return a;
    return capsocong(n - 1, a, r) + r;
}


double capsonhan(int n, int a, int q) {
    if (n == 1)
        return a;
    return capsonhan(n - 1, a, q) * q;
}


void displayAP(int n, int a, int r) {
    printf("thong tin %d:\n", a, r);
    for (int i = 1; i <= n; ++i) {
        printf("%g ", capsocong(i, a, r));
        if (i % 10 == 0)
            printf("\n");
    }
    printf("\n");
}


void displayGP(int n, int a, int q) {
    printf("cap so nhan %d:\n", a, q);
    for (int i = 1; i <= n; ++i) {
        printf("%g ", capsonhan(i, a, q));
        if (i % 10 == 0)
            printf("\n");
    }
    printf("\n");
}

int main() {
    int n, a, r, q;
    printf("(n): ");
    scanf("%d", &n);
    printf("(a): ");
    scanf("%d", &a);
    printf("(r): ");
    scanf("%d", &r);
    printf("(q):");
    scanf("%d", &q);

    displayAP(n, a, r);
    displayGP(n, a, q);

    return 0;
}

