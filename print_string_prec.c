#include "header.h"



int print_string_prec(char *str, int prec)
{
    while(*str && prec)
    {
        write(1, &(*str++), 1);
        prec--;    
    }
}