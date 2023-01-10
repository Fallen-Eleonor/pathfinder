#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    int ln = mx_strlen(str);
    char *dupl = mx_strnew(ln);
    if (dupl == NULL) return NULL;

    mx_strcpy(dupl, str);
    return dupl;
}

