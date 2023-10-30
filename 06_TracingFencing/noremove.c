#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>


typedef int (*remove_type)(void);

int remove(char *file) {
    if (strstr(file, "PROTECT") == 0) {
        return ((remove_type)(dlsym(RTLD_NEXT, "remove")))();
    } else {
        return 0;
    }
}