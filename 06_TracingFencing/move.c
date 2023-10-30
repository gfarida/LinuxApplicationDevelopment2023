#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: move infile outfile\n");
        exit(1);
    }

    FILE *in, *out;
    char c;

    if (access(argv[2], F_OK) != -1) {
        if (truncate(argv[2], 0) == -1) {
            fprintf(stderr, "Can't clean file %s with error %s\n", 
                    argv[2], strerror(errno));
            exit(errno);
        }
    }

    in = fopen(argv[1], "r");
    if (in == NULL) {
        fprintf(stderr, "Can't open file %s with error %s\n", 
                argv[1], strerror(errno));
        exit(errno);
    }

    out = fopen(argv[2], "w");
    if (out == NULL) {
        fprintf(stderr, "Can't open file %s with error %s\n", 
                argv[2], strerror(errno));
        fclose(in);
        exit(errno);
    }

    while ((c = fgetc(in)) != EOF) {
        if (fputc(c, out) == EOF) {
            fprintf(stderr, "Can't write symbol to %s with error %s\n", 
                    argv[2], strerror(errno));
            fclose(in);
            fclose(out);
            remove(argv[2]);
            exit(errno);
        }
    }

    fclose(in);
    fclose(out);


    if (remove(argv[1]) != 0) {
        fprintf(stderr, "Can't remove file %s with error %s\n", 
                argv[1], strerror(errno));
        remove(argv[2]);
        exit(errno);
    }

    return 0;
}