/* Make sure these don't segfault */
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	static char *s_hidden = "damn good job. bloody good damn good bloody good damn good job. \0 you are an excellent woman \0\0\0\0 this is not supposed to show";

	printf("%9.2p\n", 1234);
	printf("%2.9p\n", 1234);
	printf("%.5p\n", 0);
	printf("%.0p\n", 0);
	printf("%5p\n", 0);
	printf("%00s", s_hidden);
	printf("%000s", s_hidden);
	printf("%0000s", s_hidden);
	printf("%-00s", s_hidden);
	printf("%0-0s", s_hidden);
	printf("%00-s", s_hidden);
	printf("%03s", s_hidden);
	printf("%09s", s_hidden);
	printf("%-03s", s_hidden);
	printf("%-09s", s_hidden);
	printf("%0-8.5i", 34);
	printf("%0-10.5i", -216);
	printf("%0-8.5i", 0);
	printf("%0-8.3i", 8375);
	printf("%0-8.3i", -8473);
	printf("%0-3.7i", 3267);
	printf("%0-3.7i", -2375);
	printf("%0-3.3i", 6983);
	printf("%0-3.3i", -8462);
	printf("%0-8.5d", 34);
	printf("%0-10.5d", -216);
	printf("%0-8.5d", 0);
	printf("%0-8.3d", 8375);
	printf("%0-8.3d", -8473);
	printf("%0-3.7d", 3267);
	printf("%0-3.7d", -2375);
	printf("%0-3.3d", 6983);
	printf("%0-3.3d", -8462);
	printf("%0-8.5u", 34);
	printf("%0-8.5u", 0);
	printf("%0-8.3u", 8375);
	printf("%0-3.7u", 3267);
	printf("%0-3.3u", 6983);
	printf("%0-8.5x", 34);
	printf("%0-8.5x", 0);
	printf("%0-8.3x", 8375);
	printf("%0-2.7x", 3267);
	printf("%0-3.3x", 6983);
	printf("%x", INT_MIN);
	printf("%x", INT_MAX);
	printf("%05s", "hello");
	printf("%0s", "hello");
	printf("%-s", "hello");
	printf("%05c", 'a');
	printf("%0c", 'a');
	printf("%-021s", "abc");
	printf("%-05s", "goes over");
	printf("%04.3s%-7.4s", "hello", "world");
	printf("%021s", NULL);
	printf("%02s", NULL);
	printf("%-021s", NULL);
	printf("%-03s", NULL);
	printf("%05c", '\0');
	printf("%-05c", '\0');
	printf("%.4c", 'a');	
	printf("%-"); 
	printf("%23"); 
	printf("%."); 
	printf("%p"); 
	printf("%d"); 
	printf("%u"); 
	printf("%x"); 
	printf("%X"); 
	printf("%c");
	printf("%d", NULL); 
	printf("%u", NULL); 
	printf("%x", NULL); 
	printf("%X", NULL); 
	printf("%f", NULL); 
	printf("%s", NULL); 
	printf("%c", NULL);
}
