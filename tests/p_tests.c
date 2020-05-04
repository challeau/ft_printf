#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	static char	a01;
	static unsigned char a02;
	/* static short a03; */
	/* static unsigned short a04; */
	/* static int a05; */
	/* static unsigned int a06; */
	/* static long a07; */
	/* static unsigned long a08; */
	/* static long long a09; */
	/* static unsigned long long a10; */
	/* static char *a11; */
	/* static void *a12; */

	ft_printf("%p\n", NULL);
	ft_printf("%5p\n", NULL);
	ft_printf("%2p\n", NULL);
	ft_printf("%.p\n", NULL);
	ft_printf("%5.1p\n", NULL);
	ft_printf("%2.p\n", NULL);

	/* ft_printf("%p%p%p%p%p%p%p%p%p%p%p%p\n\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12); */
	/* ft_printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p\n\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12); */
	/* ft_printf("%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p\n\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12); */
	/* ft_printf("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12); */
	/* ft_printf("%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12); */

	/* printf("%p\n", NULL); */
	/* printf("%5p\n", NULL); */
	/* printf("%2p\n", NULL); */
	/* printf("%.p\n", NULL); */
	/* printf("%5.p\n", NULL); */
	/* printf("%2.p\n", NULL); */
	/* printf("%p%p%p%p%p%p%p%p%p%p%p%p\n\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12); */
	/* printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p\n\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12); */
	/* printf("%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p\n\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12); */
	/* printf("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12); */
	/* printf("%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12); */
	
	return (0);
}
