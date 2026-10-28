#include "header.h"



int valid_format(char c)
{
    char *str;

    str = "sdipuXxc";
    while(*str)
    {
        if(*str == c)
            return 1;
        str++;
    }
    return 0;
}

int despatch_flags(s_form *forms, va_list args)
{
    if(forms->F == 'c')
        return (ft_parse_char(forms, va_arg(args, int)));
    return 0;
}

char *get_flags(const char *s, s_form *format)
{
    char *str;

    str = (char *)s;
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
            format->precision = format->precision * 10 + (*str++ - 48);
    }
    if(valid_format(*str))
        format->F = *str;
    return str;
}

int ft_printf(const char *args, ...)
{
    va_list ap;
    int count;
    s_form form;


    count = 0;
    va_start(ap, args);
    while(*args)
    {
        if(*args == '%' && (*(args + 1) != '%'))
        {
            args++;
            form = (s_form){0};
            form.precision = -1;
            args = get_flags(args, &form);
            count += despatch_flags(&form, ap);
        }
        else
            count += write(1, &(*args), 1);
        args++;
    }
    va_end(ap);
    return count;
}


int main()
{
    printf("%c\n", 'c');
    ft_printf("%c\n", 'c');
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