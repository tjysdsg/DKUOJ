#include <cstdio>

static char* M[] = {"", "M", "MM", "MMM"};
static char* C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
static char* X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
static char* I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

int main() {
    int num = 0;
    scanf("%d", &num);
    printf("%s%s%s%s\n", M[num / 1000], C[(num % 1000) / 100],
           X[(num % 100) / 10], I[num % 10]);
    return 0;
}
