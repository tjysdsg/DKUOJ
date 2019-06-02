#include <stdio.h>
int main() {
    int cases, n, i, j, min, max;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        min = 100;
        max = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &j);
            if (j > max) max = j;
            if (j < min) min = j;
        }
        printf("%d\n", (max - min) * 2);
    }
    return 0;
}
