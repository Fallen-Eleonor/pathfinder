#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int low = 0;
    int high = size - 1;
    int middle;
    int i = 0;
    low = 0;
    while (low <= high) {
        i++;
        middle = (low + high) / 2;
        if (mx_strcmp(s, arr[middle]) < 0)
            high = middle - 1;
        else if (mx_strcmp(s, arr[middle]) > 0)
            low = middle + 1;
        else {
            *count = i;
            return middle;
        }
    }
    i = 0;
    *count = i;
    return -1;
}


