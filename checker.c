#include <stdio.h>

void test();
void ft_puts(char *str);
void test3();

void dbg_int(int x)
{
	printf("=> %d\n", x);
}

void dbg_char(char c)
{
	printf("=> %c\n", c);
}

void dbg_str(char *str)
{
	printf("=> %s\n", str);
}

int main(void)
{
	char str[] = "this is a long test with a lot of words in it\n";
	printf("//////////////////////////////////\n");
	printf("                                  \n");
	printf("         LIBFT ASM CHECKER        \n");
	printf("                                  \n");
	printf("//////////////////////////////////\n\n");
	ft_puts(str);
	ft_puts("don't touch this\n");
	ft_puts("");
	return 0;
}
