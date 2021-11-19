/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:09:05 by ozahir            #+#    #+#             */
/*   Updated: 2021/11/19 04:53:03 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putnbr_fd(int nb, int fd)
{
	long	a;

	a = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		a *= -1;
	}
	if (a > 9)
	{
		ft_putnbr_fd(a / 10, fd);
		ft_putnbr_fd(a % 10, fd);
	}
	else
		ft_putchar_fd(a + '0', fd);
}
void	ft_bzero(void *s, size_t n)
{
	char	*b;

	b = (char *)s;
	while (n)
	{
		*b = 0;
		b++;
		n--;
	}
}

void	unsigned_ft_putnbr_fd(unsigned int nb, int fd)
{
	unsigned long	a;

	a = nb;
	if (a > 9)
	{
		ft_putnbr_fd(a / 10, fd);
		ft_putnbr_fd(a % 10, fd);
	}
	else
		ft_putchar_fd(a + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
void hexconvert(uint64_t n,int c)
{	int i = 0;
	int rem = 0;
	char hexnum[65];
	int b  = 0;
	if (c == 1)
	   b = 32;
	ft_bzero(hexnum, 65);
	  while(n!=0)
    {
        rem = n%16;
        if(rem<10)
            rem = rem+48;
        else
            rem = rem+55;
		if (rem <= '9' && rem >= '0')
			hexnum[i] = rem;
		else
			hexnum[i] = rem + b;
        i++;
        n = n/16;
    }
	  ft_putstr_fd("0x",1);
	  ft_putstr_fd(hexnum,1);


}
void reverseprint(char *str)
{
	int i = 0;
while (str[i])
	i++;
while (i != -1)
{
	ft_putchar_fd(str[i], 1);
	i--;
}
}
void p_print(uint64_t n)
{	int i = 0;
	int rem = 0;
	char hexnum[65];
	ft_bzero(hexnum,65);
	  while(n!=0)
    {
        rem = n%16;
        if(rem<10)
            rem = rem+48;
        else
            rem = rem+55;
		if (rem <= '9' && rem >= '0')
			hexnum[i] = rem ;
		else
			hexnum[i] = rem +32;
        i++;
        n = n/16;
    }
	  ft_putstr_fd("0x",1);
	  reverseprint(hexnum);


}
static int print_pars(char c, va_list args)
{
	if (c == 'd' || c == 'i' )
	{
		int i = va_arg(args, int);
		ft_putnbr_fd(i,1);
	}
	if (c == 'c')
	{
		int i = va_arg(args,int);
		ft_putchar_fd(i,1);
	}
	else if (c == 's')
	{
		char *s = va_arg(args,char*);
		ft_putstr_fd(s,1);
	}
	else if (c == 'u')
	{
		unsigned int i = va_arg(args,unsigned int );
		unsigned_ft_putnbr_fd(i, 1);
	}
	else if (c == 'x')
	{
		int i = va_arg(args, int);
	   hexconvert(i, 1);	
	}
	else if (c == 'X')
	{
		int i = va_arg(args,int);
		hexconvert(i,0);
	}
	else if(c == 'p')
	{
		void *p = va_arg(args,void*);
		p_print((uint64_t)p);
	}
	else if (c == '%')
		ft_putchar_fd('%',1);
	return (0);
}
int	ft_printf(const char *s, ...)
{
	va_list args;
	va_start(args, s);
	int	reach;
	int	i;

	i = 0;
	reach = 0;
	while(*s)
	{	
		 if (reach == 0)
		{
			if (*s == '%')
			{
				reach = 1;
			}
			else
				ft_putchar_fd(*s,1);
		}
		else if (reach == 1)
		{
			i = print_pars(*s,args);
			reach = 0;
		}
	s++;	
	}
	va_end(args);
	return (i);
}
#include <stdio.h>

int main()
{
	char *p = "dgfdgdfgdf";
	ft_printf("print a char: %c and %d and %s and %c\n",'d', 23,"njklm", 'a');

	ft_printf("print a string: %s\n" ,"-hahaha-");
	ft_printf("print  number: %d\n", 22);
	ft_printf("print i minus number %d\n", -55 );

	ft_printf("print an intejger %i, \n", 453);
	ft_printf("print an unsigneddecimal %u\n");
	ft_printf("print a number in hex lower case %x\n", 266);
	ft_printf("print a hex in upper case %X\n", 266);
	ft_printf(" a percent sign %% \n");
	ft_printf("\n  here it comes %p   \n",p);
	printf("\n hehehe %p \n", p);
}
