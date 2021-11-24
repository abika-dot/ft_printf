#include "ft_printf.h"
#include <stdio.h>
int main()
{
	int a = printf("%x\n", 0);
	int b = ft_printf("%x\n",0);
	
	printf("other: %d  ----> mine :%d\n",a,b);
	
	a = printf("%X\n",0);
	b = ft_printf("%X\n",0);
	printf("%d    %d",a,b);
}
