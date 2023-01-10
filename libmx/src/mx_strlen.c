#include "../inc/libmx.h"

int mx_strlen(const char *s) {
	int r = 0;
	while(*s != 0) {
	s++;
	r++;
	}
	return r;
}

