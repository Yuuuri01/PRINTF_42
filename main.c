#include <stdio.h>
#include <stdarg.h>
#include <header.h>



int valid_format(char c)
{
    char *str;

    str = "sdipXxc";
    while(*str)
    {
        if(*str == c)
            return 1;
        str++;
    }
    return 0;
}

int despatch_flags(s_form *forms, const char *args)
{

}

char *get_flags(const char *str, s_form *format)
{
    s_form formes;
    while(*str == '#' || *str == '-' || *str == '+' || *str == '0' || *str == ' ')
    {
        if(*str == '#')
            format->hash = 1;
        else if(*str == '-')
            format->minus = 1;
        else if(*str == '+')
            format->plus = 1;
        else if(*str == '0')
            format->zero = 1;
        else if(*str == ' ')
            format->space = 1;
        str++;
    }
    format->width = 0;
    while(*str >= '0' && *str <= '9')
        format->width = format->width * 10 + (*str++ - 48);
    if(*str == '.')
    {
        format->precision = 0;
        str++;
        while(*str >= '0' && *str <= '9')
        
    }
    return str;
}

int ft_printf(const char *args, ...)
{
    va_list ap;
    int count;
    s_form form;

    form.precision = -1;
    va_start(ap, args);
    while(*args)
    {
        if(*args == '%')
        {
            args++;
            args = get_flags(args, &form);
            count += despatch_flags(&form, args);
        }

    }
}

//%  flags  width  .precision  length  specifier

//  %   -    10    .3        l       d
//  ↑   ↑     ↑     ↑        ↑       ↑
//  |   |     |     |        |       └─ specifier (type)
//  |   |     |     |        └───────── length modifier
//  |   |     |     └────────────────── precision (starts with .)
//  |   |     └──────────────────────── width
//  |   └────────────────────────────── flags
//  └────────────────────────────────── starts the format