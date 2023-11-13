#include <stdio.h>

int main(int argc, char **argv) {
    printf("Загадайте число от 1 до 100 и введите его:\n");

    int n;
    char ans[100];
    scanf("%d", &n);
    int b = 1, e = 100, c = 50;


    while (true) {
        printf("Число больше %d? Да/Нет \n", c);
        scanf("%s", ans);

        if (!cmp(ans, "Да")) {
            b = c;
        } else {
            e = c;
        }

        c = (e - b) / 2;

        if (e == b) {
            printf("Ваше число - это %d\n", e);
            break;
        }
    }
    return 0;
}