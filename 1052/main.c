#include <stdio.h>

int main() {
    float data[12] = {0.00};
    float sum = 0.00;
    float average = 0.00;
    int i = 0;
    for (i = 0; i < 12; i++) {
        scanf("%f", &data[i]);
        sum = data[i] + sum;
    }
    average = sum / 12;
    printf("$%.2f", average);
    return 0;
}
