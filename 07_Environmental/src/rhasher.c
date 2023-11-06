#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "rhash.h"
#ifdef READLINE
#include <readline/readline.h>
#endif

enum {_MD5, MD5, _SHA1, SHA1, _TTH, TTH, UNKNOWN_MODE};

int parsing_hash_mode(char *hash_alg) {
    if (!strcmp(hash_alg, "md5")) {
        return _MD5;
    }
    
    if (!strcmp(hash_alg, "MD5")) {
        return MD5;
    }

    if (!strcmp(hash_alg, "sha1")) {
        return _SHA1;
    }

    if (!strcmp(hash_alg, "SHA1")) {
        return SHA1;
    }

    if (!strcmp(hash_alg, "tth")) {
        return _TTH;
    }

    if (!strcmp(hash_alg, "TTH")) {
        return TTH;
    }

    return UNKNOWN_MODE;
}

bool is_file_check(char *string) {
    if (string[0] == '"') {
        return false;
    }

    return true;
}

void hashing(int hash_mode, char *string, bool is_file) {
    char digest[64];
    char output[130];
    int res;

    switch(hash_mode) {
        case _MD5:
            if (is_file) {
                res = rhash_file(RHASH_MD5, string, digest);
                if (res < 0) {
                    fprintf(stderr, "LibRHash error: %s\n", strerror(errno));
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_MD5), RHPR_BASE64);
                }
            } else {
                res = rhash_msg(RHASH_MD5, string, strlen(string), digest);
                if (res < 0) {
                    fprintf(stderr, "message digest calculation error\n");
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_MD5), RHPR_BASE64);
                }
            }
            printf("%s\n", output);
            break;
        case MD5:
            if (is_file) {
                res = rhash_file(RHASH_MD5, string, digest);
                if (res < 0) {
                    fprintf(stderr, "LibRHash error: %s\n", strerror(errno));
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_MD5), RHPR_HEX);
                }
            } else {
                res = rhash_msg(RHASH_MD5, string, strlen(string), digest);
                if (res < 0) {
                    fprintf(stderr, "message digest calculation error\n");
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_MD5), RHPR_HEX);
                }
            }
            printf("%s\n", output);
            break;
        case _SHA1:
            if (is_file) {
                res = rhash_file(RHASH_SHA1, string, digest);
                if (res < 0) {
                    fprintf(stderr, "LibRHash error: %s\n", strerror(errno));
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_SHA1), RHPR_BASE64);
                }
            } else {
                res = rhash_msg(RHASH_SHA1, string, strlen(string), digest);
                if (res < 0) {
                    fprintf(stderr, "message digest calculation error\n");
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_SHA1), RHPR_BASE64);
                }
            }
            printf("%s\n", output);
            break;
        case SHA1:
            if (is_file) {
                res = rhash_file(RHASH_SHA1, string, digest);
                if (res < 0) {
                    fprintf(stderr, "LibRHash error: %s\n", strerror(errno));
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_SHA1), RHPR_HEX);
                }
            } else {
                res = rhash_msg(RHASH_SHA1, string, strlen(string), digest);
                if (res < 0) {
                    fprintf(stderr, "message digest calculation error\n");
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_SHA1), RHPR_HEX);
                }
            }
            printf("%s\n", output);
            break;
        case _TTH:
            if (is_file) {
                res = rhash_file(RHASH_TTH, string, digest);
                if (res < 0) {
                    printf("%s", string);
                    fprintf(stderr, "LibRHash error: %s\n", strerror(errno));
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_TTH), RHPR_BASE64);
                }
            } else {
                res = rhash_msg(RHASH_TTH, string, strlen(string), digest);
                if (res < 0) {
                    fprintf(stderr, "message digest calculation error\n");
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_TTH), RHPR_BASE64);
                }
            }
            printf("%s\n", output);
            break;
        case TTH:
            if (is_file) {
                res = rhash_file(RHASH_TTH, string, digest);
                printf("dsnflsdf\n");
                if (res < 0) {
                    printf("%s", string);
                    fprintf(stderr, "LibRHash error: %s\n", strerror(errno));
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_TTH), RHPR_HEX);
                }
            } else {
                res = rhash_msg(RHASH_TTH, string, strlen(string), digest);
                if (res < 0) {
                    fprintf(stderr, "message digest calculation error\n");
                } else {
                    rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_TTH), RHPR_HEX);
                }
            }
            printf("%s\n", output);
            break;
    }
}

int main(int argc, char **argv) {
    char *line = NULL, *hash_alg, *string;
    bool is_file;
    size_t len = 0;
    ssize_t nread;
    int hash_mode;
    rhash_library_init();

    while (true) {
#ifdef READLINE
        line = readline(NULL);

        if (!line) {
            nread = -1;
        }
#else
        nread = getline(&line, &len, stdin);

        if (nread == -1) {
            break;
        }
#endif
        
        hash_alg = strtok(line, " ");
        string = strtok(NULL, " ");

        hash_mode = parsing_hash_mode(hash_alg);

        if (hash_mode == UNKNOWN_MODE) {
            fprintf(stderr, "Неопознанная команда: %s\n", hash_alg);
            continue;
        }

        is_file = is_file_check(string);

        if (!is_file) {
            char string_[100];
            string = string + 1;
            memcpy(string_, string, strlen(string) - 1);
            string_[strlen(string)] = '\0';
            hashing(hash_mode, string_, is_file);
        } else {
            char filepath[100];
            memcpy(filepath, string, strlen(string) - 1);
            filepath[strlen(string)] = '\0';
            hashing(hash_mode, filepath, is_file);
        }
    }

    return 0;
}