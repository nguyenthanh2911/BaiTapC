#include <stdio.h>


void xuatnhiphan(int n) {
    if (n > 0) {
        xuatnhiphan(n / 2);
        printf("%d", n % 2);
    }
}

int main() {
    int n;
    printf("(n): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("\n");
        return 1;
    }

    printf("%d: ", n);
    xuatnhiphan(n);
    printf("\n");

    return 0;
}

