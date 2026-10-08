#include <stdio.h>

int main() {
    int rows = 6;

    for (int i = 1; i <= rows; i++) {
        // 印出前導空格以置中
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        // 印出數字與空格
        for (int k = 1; k <= i; k++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
