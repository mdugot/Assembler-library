#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PRINTF(x...) printf(x); fflush(stdout)
#define R(x) r = x; printf("=> %d\n", r); fflush(stdout)
#define L(x) l = x; printf("=> %zu\n", l); fflush(stdout)
#define S(x) s = x; printf("=> %s\n", s); fflush(stdout)
#define D(x, m, s) x; dump(m, s)

int ft_puts(char *str);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isprint(int c);
void ft_bzero(void *s, size_t n);
char *ft_strcat(char *restrict s1, const char *restrict s2);
size_t ft_strlen(const char *s);
void *ft_memset(void *b, int c, size_t len);
void *ft_memcpy(void *dst, void *src, size_t n);
char *ft_strdup(const char *s1);

void dump(char *mem, size_t size)
{
	size_t i;

	PRINTF("dump :\n");
	for (i = 0; i < size; i++)
		PRINTF("%#hhx\n", mem[i]);
}


int main(void)
{
	char mem[100];
	int r;
	size_t l;
	char *s;

	PRINTF("//////////////////////////////////\n");
	PRINTF("//                              //\n");
	PRINTF("//       LIBFT ASM CHECKER      //\n");
	PRINTF("//                              //\n");
	PRINTF("//////////////////////////////////\n\n");

	PRINTF(".............. strdup ............\n\n");
	S(LIB(strdup)("test\n"));
	free(s);
	S(LIB(strdup)("second test\n"));
	free(s);
	S(LIB(strdup)(""));
	free(s);
	PRINTF(".............. memcpy ............\n\n");
	LIB(bzero(mem, 100));
	D(LIB(memcpy)(mem, "qwertyuiopasdfghjk", 8), mem, 10);
	D(LIB(memcpy)(mem, "1234567890", 4), mem, 10);
	D(LIB(memcpy)(mem, "-=-=-=-=-=-=", 1), mem, 10);
	D(LIB(memcpy)(mem, "@@@@", 0), mem, 10);
//	D(LIB(memcpy)(mem, &mem[3], 5), mem, 10);
//	D(LIB(memcpy)(&mem[3], mem, 5), mem, 10);
	PRINTF(".............. memset ............\n\n");
	LIB(bzero(mem, 100));
	D(LIB(memset)(mem, '*', 8), mem, 10);
	D(LIB(memset)(mem, ' ', 4), mem, 10);
	D(LIB(memset)(mem, 'A', 1), mem, 10);
	D(LIB(memset)(mem, '0', 0), mem, 10);
	D(LIB(memset)(mem, (int)mem[3], 5), mem, 10);
	D(LIB(memset)(&mem[3], (int)mem[3], 5), mem, 10);
	PRINTF(".............. strlen ............\n\n");
	L(LIB(strlen)("test"));
	L(LIB(strlen)(""));
	L(LIB(strlen)(" \b\t@#$%^&*sudgi867586\n\t"));

	PRINTF(".............. strcat ............\n\n");
	strcpy(mem, "premier ");
	S(LIB(strcat)(mem, "test\n"));
	strcpy(mem, "");
	S(LIB(strcat)(mem, "second test\n"));
	strcpy(mem, "troisieme test\n");
	S(LIB(strcat)(mem, ""));
	strcpy(mem, "quatrieme test");
	S(LIB(strcat)(mem, "\n"));
	strcpy(mem, "d");
	S(LIB(strcat)(mem, "ernier test\n"));
	PRINTF(".............. bzero .............\n\n");
	LIB(memcpy)(mem, "0123456789", 10);
	D(LIB(bzero)(mem, 10), mem, 10);
	LIB(memcpy)(mem, "0123456789", 10);
	D(LIB(bzero)(mem, 4), mem, 10);
	LIB(memcpy)(mem, "0123456789", 10);
	D(LIB(bzero)(mem, 0), mem, 10);
	PRINTF("............... puts .............\n\n");
	char str[] = "this is a long test with a lot of words in it\n";
	R(LIB(puts)(str));
	R(LIB(puts)("don't touch this\n"));
	R(LIB(puts)(""));
	R(LIB(puts)("\n"));
	R(LIB(puts)(0));
	PRINTF("............. toupper ............\n\n");
	R(LIB(toupper)('0'));
	R(LIB(toupper)('5'));
	R(LIB(toupper)('9'));
	R(LIB(toupper)('x'));
	R(LIB(toupper)('a'));
	R(LIB(toupper)('z'));
	R(LIB(toupper)('X'));
	R(LIB(toupper)('A'));
	R(LIB(toupper)('Z'));
	R(LIB(toupper)('!'));
	R(LIB(toupper)(' '));
	R(LIB(toupper)('~'));
	R(LIB(toupper)('\t'));
	R(LIB(toupper)(96));
	R(LIB(toupper)(123));
	R(LIB(toupper)(-1));
	R(LIB(toupper)(0));
	R(LIB(toupper)(1));
	R(LIB(toupper)(999));
	R(LIB(toupper)(2000));
	R(LIB(toupper)(123456));
	PRINTF("............. tolower ............\n\n");
	R(LIB(tolower)('0'));
	R(LIB(tolower)('5'));
	R(LIB(tolower)('9'));
	R(LIB(tolower)('x'));
	R(LIB(tolower)('a'));
	R(LIB(tolower)('z'));
	R(LIB(tolower)('X'));
	R(LIB(tolower)('A'));
	R(LIB(tolower)('Z'));
	R(LIB(tolower)('!'));
	R(LIB(tolower)(' '));
	R(LIB(tolower)('~'));
	R(LIB(tolower)('\t'));
	R(LIB(tolower)(96));
	R(LIB(tolower)(123));
	R(LIB(tolower)(-1));
	R(LIB(tolower)(0));
	R(LIB(tolower)(1));
	R(LIB(tolower)(999));
	R(LIB(tolower)(2000));
	R(LIB(tolower)(123456));
	PRINTF("............. isalpha ............\n\n");
	R(LIB(isalpha)('0'));
	R(LIB(isalpha)('5'));
	R(LIB(isalpha)('9'));
	R(LIB(isalpha)('a'));
	R(LIB(isalpha)('z'));
	R(LIB(isalpha)('x'));
	R(LIB(isalpha)('X'));
	R(LIB(isalpha)('A'));
	R(LIB(isalpha)('Z'));
	R(LIB(isalpha)('!'));
	R(LIB(isalpha)(' '));
	R(LIB(isalpha)('~'));
	R(LIB(isalpha)('\t'));
	R(LIB(isalpha)(96));
	R(LIB(isalpha)(123));
	R(LIB(isalpha)(-1));
	R(LIB(isalpha)(0));
	R(LIB(isalpha)(1));
	R(LIB(isalpha)(999));
	R(LIB(isalpha)(2000));
	R(LIB(isalpha)(123456));
	PRINTF("............. isdigit ............\n\n");
	R(LIB(isdigit)('0'));
	R(LIB(isdigit)('5'));
	R(LIB(isdigit)('9'));
	R(LIB(isdigit)('a'));
	R(LIB(isdigit)('z'));
	R(LIB(isdigit)('x'));
	R(LIB(isdigit)('X'));
	R(LIB(isdigit)('A'));
	R(LIB(isdigit)('Z'));
	R(LIB(isdigit)('!'));
	R(LIB(isdigit)(' '));
	R(LIB(isdigit)('~'));
	R(LIB(isdigit)('\t'));
	R(LIB(isdigit)(96));
	R(LIB(isdigit)(123));
	R(LIB(isdigit)(-1));
	R(LIB(isdigit)(0));
	R(LIB(isdigit)(1));
	R(LIB(isdigit)(999));
	R(LIB(isdigit)(2000));
	R(LIB(isdigit)(123456));
	PRINTF("............. isalnum ............\n\n");
	R(LIB(isalnum)('0'));
	R(LIB(isalnum)('5'));
	R(LIB(isalnum)('9'));
	R(LIB(isalnum)('a'));
	R(LIB(isalnum)('z'));
	R(LIB(isalnum)('x'));
	R(LIB(isalnum)('X'));
	R(LIB(isalnum)('A'));
	R(LIB(isalnum)('Z'));
	R(LIB(isalnum)('!'));
	R(LIB(isalnum)(' '));
	R(LIB(isalnum)('~'));
	R(LIB(isalnum)('\t'));
	R(LIB(isalnum)(96));
	R(LIB(isalnum)(123));
	R(LIB(isalnum)(-1));
	R(LIB(isalnum)(0));
	R(LIB(isalnum)(1));
	R(LIB(isalnum)(999));
	R(LIB(isalnum)(2000));
	R(LIB(isalnum)(123456));
	PRINTF("............. isprint ............\n\n");
	R(LIB(isprint)('0'));
	R(LIB(isprint)('5'));
	R(LIB(isprint)('9'));
	R(LIB(isprint)('a'));
	R(LIB(isprint)('z'));
	R(LIB(isprint)('x'));
	R(LIB(isprint)('X'));
	R(LIB(isprint)('A'));
	R(LIB(isprint)('Z'));
	R(LIB(isprint)('!'));
	R(LIB(isprint)(' '));
	R(LIB(isprint)('~'));
	R(LIB(isprint)('\t'));
	R(LIB(isprint)(96));
	R(LIB(isprint)(123));
	R(LIB(isprint)(-1));
	R(LIB(isprint)(0));
	R(LIB(isprint)(1));
	R(LIB(isprint)(999));
	R(LIB(isprint)(2000));
	R(LIB(isprint)(123456));
	return 0;
}
