#include <stdio.h>

void range(int m, int n, int s) {
    for (int i=m; i < n; i+=s) {
        printf("%d\n", i);
    }
}

int main(int argc, char **argv) {
    switch(argc) {
        case 1:
            printf("Usage: \n"
                    "   %s N -  [0, 1, … N-1],\n"
                    "   %s M N - [M, M+1, … N-1],\n"
                    "   %s M N S - [M, M+S, M+2S, … N-1]\n", argv[0], argv[0], argv[0]);
                    break;
        case 2:
            range(0, atoi(argv[1]), 1);
            break;
        case 3:
            range(atoi(argv[1]), atoi(argv[2]), 1);
            break;
        case 4:
            range(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
            break;
    }
    return 0;
}