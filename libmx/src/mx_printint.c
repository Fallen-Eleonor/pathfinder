#include "../inc/libmx.h"

void mx_printint(int n)
{
  int st1 = 1;
  int st2;
    if (n < 0) 
    {
        mx_printchar('-');
    }
    for (int i = n / 10; i != 0; i /= 10) 
    {
        st1 *= 10;
    }
    while (st1 != 0) 
    {
        st2 = n / st1 % 10;
        if (n < 0) 
        {
            st2 *= -1;
        }
        mx_printchar(st2 + '0');
        st1 /= 10;
    }
}



