#include "../inc/libmx.h"

int mx_strlen(const char *s) {
	int r = 0;
	while(*s != 0) {
	s++;
	r++;
	}
	return r;
}

bool mx_isdigit(int c)
{
    return c >= 48 && c <= 57;
}

bool mx_islower(int c)
{
    return (c >= 97 && c <= 122);
}

bool mx_isupper(int c)
{
    return (c >= 65 && c <= 90);
}

unsigned long mx_hex_to_nbr(const char *hex)
{
    if (hex == NULL)
        return 0;
    int len = mx_strlen(hex);
    unsigned long hex_n = 1;
    unsigned long r = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (mx_isdigit(hex[i]) || ((hex[i] >= 65 && hex[i] <= 90)  || (hex[i] >= 97 && hex[i] <= 122)))
        {
            if (mx_isdigit(hex[i]))
                r += (hex[i] - 48) * hex_n;

            if (mx_isupper(hex[i]))
                r += (hex[i] - 55) * hex_n;

            if (mx_islower(hex[i]))
                r += (hex[i] - 87) * hex_n;

            hex_n *= 16;
        }
    }

    return r;
}


