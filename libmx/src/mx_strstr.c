#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    while (*haystack) {
        if (mx_strncmp(haystack, needle, mx_strlen(needle)) != 0) {
            haystack++;
        }
        else {
            break;
        }
        haystack = mx_strchr(haystack, *needle);
    }
    return (*haystack != '\0') ? (char *)haystack : '\0';
}

