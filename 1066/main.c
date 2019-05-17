#include <stdio.h>

int main() {
    int n;
    int a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%d:%d", &a, &b);

        if (b != 0) {
            printf("0\n");
            continue;
        }

        printf("%d\n", (a + 11) % 24 + 1);
    }
    return 0;
}
