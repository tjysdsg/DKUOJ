#include <stdio.h>
int N, B;
int exponentiation(int x) {
    int ans = x;
    if (x == 1) return 1;
    for (int i = N; i != 1; --i) ans *= x;
    return ans;
}

int main() {
    while (scanf("%d%d", &B, &N) != EOF) {
        if (N == 0 && B == 0) break;
        int A = 1, ans;
        int result = exponentiation(A);
        while (result < B) {
            ++A;
            result = exponentiation(A);
        }
        if (result - B < B - exponentiation(A - 1))
            printf("%d\n", A);
        else
            printf("%d\n", A - 1);
    }
    return 0;
}
