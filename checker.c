#include <stdio.h>

#define PRINTF(x) printf(x); fflush(stdout)
#define R(x) r = x; printf("=> %d\n", r); fflush(stdout)

void test();
int ft_puts(char *str);
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
	int r;

	PRINTF("//////////////////////////////////\n");
	PRINTF("                                  \n");
	PRINTF("         LIBFT ASM CHECKER        \n");
	PRINTF("                                  \n");
	PRINTF("//////////////////////////////////\n\n");

	PRINTF("............... puts .............\n\n");
	char str[] = "this is a long test with a lot of words in it\n";
	R(LIB(puts)(str));
	R(LIB(puts)("don't touch this\n"));
	R(LIB(puts)(""));
	R(LIB(puts)("\n"));
	R(LIB(puts)(0));
	return 0;
}
