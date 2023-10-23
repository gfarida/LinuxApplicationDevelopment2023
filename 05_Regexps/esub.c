#include <stdio.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXGR 10

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s regexp substitution string\n", argv[0]); 
        exit(1);
    }

    char *regexp = argv[1];
    char *substitution = argv[2];
    char *string = argv[3];

    regex_t preg;
    int     rc, regexp_code;
    char    buffer[100];
    int result_pos = 0, bag_i = 0, subst_size_i = 0, bag_len = 0, bags_number;

    regmatch_t bags[MAXGR];
    int subst_size = strlen(substitution), str_size = strlen(string);
 
    if (0 != (rc = regcomp(&preg, regexp, REG_EXTENDED))) {
        regerror(rc, &preg, buffer, 100);
        printf("regcomp() failed with '%s'\n", buffer);
        exit(EXIT_FAILURE);
    }

    if (REG_NOMATCH == (regexp_code = regexec(&preg, string, MAXGR, bags, 0))) {
        printf("No matches\n");
        regfree(&preg);
        exit(1);
    }

    char *result = (char *)malloc((str_size + subst_size) * sizeof(char));

    //до поставновки
    memcpy(result, string, bags[0].rm_so);
    result_pos += bags[0].rm_so;

    //подстановка
    for (int i = 0; i < subst_size; ++i) {
        
        if (substitution[i] == '\\' && i < subst_size - 1 && substitution[i + 1] == '\\') {
            result[result_pos] = '\\';
            ++result_pos;
            continue;
        }

        if (substitution[i] == '\\') {
            continue;
        }

        if (isdigit(substitution[i])) {
            bag_i = substitution[i] - '0';

            if (bags[bag_i].rm_so == -1) {
                printf("This bag doesn't exist\n");
                regfree(&preg);
                exit(1);
            }
            bag_len = bags[bag_i].rm_eo - bags[bag_i].rm_so;
            memcpy(result + result_pos, string + bags[bag_i].rm_so, bag_len);
            result_pos += bag_len;
            continue;
        }
        
        result[result_pos] = substitution[i];
        ++result_pos;
    }

    //после подстановки
    memcpy(result + result_pos, string + bags[0].rm_eo, str_size - bags[0].rm_eo + 1);

    //конец строки
    result[str_size + result_pos + str_size - bags[0].rm_eo] = '\0';

    printf("%s\n", result);

    free(result);
    regfree(&preg);
    return 0;
}
