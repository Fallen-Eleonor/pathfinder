#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if( x == __INT_MAX__) {
        return 0;
    }
    int sqr = 0;
    for (int i = 2; sqr < x; i++) {
        sqr = i * i;
        if (sqr == x) {
            return i;
        }
    }
    return 0;
}

