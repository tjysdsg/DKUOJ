#include <cstdio>
#include <cstring>
using namespace std;

struct poj {
    char s[1005];
    int v;
} ch[10005];

int js(char s[]) {
    int ans = 0, A = 0, C = 0, G = 0, T = 0, len;
    len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        switch (s[i]) {
            case 'A':
                A++;
                break;
            case 'C':
                C++;
                ans += A;
                break;
            case 'G':
                G++;
                ans += A + C;
                break;
            case 'T':
                T++;
                ans += A + C + G;
                break;
            default:
                break;
        }
    }
    return ans;
}

void swapx(int i, int j) {
    struct poj tmp;
    tmp = ch[i];
    ch[i] = ch[j];
    ch[j] = tmp;
}

void Qsort(int l, int r) {
    int i, j, x;
    i = l;
    j = r;
    x = ch[(l + r) / 2].v;
    while (i <= j) {
        while (ch[i].v < x) i++;
        while (ch[j].v > x) j--;
        if (i <= j) {
            swapx(i, j);
            i++;
            j--;
        }
    }
    if (l < j) Qsort(l, j);
    if (i < r) Qsort(i, r);
}

int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", ch[i].s);
        ch[i].v = js(ch[i].s);
    }
    Qsort(1, n);
    for (int i = 1; i <= n; i++) printf("%s\n", ch[i].s);
}
