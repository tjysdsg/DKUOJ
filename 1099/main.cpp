#include <stdio.h>

int main() {
    char ch;
    int sum, i;
    while (1) {
        ch = getchar();
        if (ch == '#') break;
        sum = 0;
        i = 1;
        sum += (ch - 'A' + 1) * (i++);

        while (1) {
            ch = getchar();
            if (ch == '\n') break;
            if (ch == ' ')
                i++;
            else {
                sum += (ch - 'A' + 1) * (i++);
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}
