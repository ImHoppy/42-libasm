int ft_strlen(const char *);
char *ft_strcpy(char *, const char *);
char *ft_strcpy(char *, const char *);
int ft_strcmp(const char *, const char *);

#include <stdio.h>
#include <string.h>

int main()
{
	const char *a = "Hello world !";
	char dst[20] = {};
	const char *b = ft_strcpy(dst, a);
	printf("dst = %s %s\n", dst, b);
	printf("len = %d\n", ft_strlen(dst));

	// printf("ft_strcmp = %d strcmp = %d\n", ft_strcmp(a, b), strcmp(a, b));
	printf("ft_strcmp = %d strcmp = %d\n", ft_strcmp(a, "Hello world  "), strcmp(a, "Hello world  "));

	return 0;
}