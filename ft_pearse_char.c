#include "header.h"


int ft_print_char(char c, int length)
{
    int i = 0;
    while(i < length)
    {
        write(1, &c, 1);
        i++;
    }
    return length;
}



int ft_parse_char(s_form *form, int c)
{
    int count = 0;

    form->sp_padding = form->width - (form->zero_padding + 1);
    if(form->sp_padding < 0)
        form->sp_padding = 0;
    if(!form->minus)
    {
        count += ft_print_char(' ', form->sp_padding);
    }
    if(form->space)
    {
        count += write(1, " ", 1);
    }
    count += write(1, &c, 1);
    if(form->minus)
        count += ft_print_char(' ', form->sp_padding);
    count += 1;
    return count;
}