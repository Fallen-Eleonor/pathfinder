#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub)
{
    if (str == NULL || sub == NULL) {
        return -2;
    }
    int count = 0;
    while (*str) {
        mx_strstr(str, sub);
        count++;
        str++;
        str = mx_strchr(str, *sub);
    }
    return count;
}


