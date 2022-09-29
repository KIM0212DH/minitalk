#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
    char *null_str = NULL;

    int ft_ret = ft_printf("ft_printf :%s", null_str);

    ft_printf("\n%p", &ft_ret);
    ft_printf("This %p is even stranger", (void *)-1);
}
