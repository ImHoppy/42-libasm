#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int ft_strlen(const char *);
char *ft_strcpy(char *, const char *);
int ft_strcmp(const char *, const char *);
ssize_t ft_write(int fd, const void *buf, size_t count);

void test_ft_write(int fd, char *b, size_t len)
{
	const int ret_write = write(fd, b, len);
	printf("write %d, errno = %d\n", ret_write, errno);
	errno = 0;
	const int ret_ft_write = ft_write(fd, b, len);
	printf("ft_write %d, errno = %d\n", ret_ft_write, errno);
	errno = 0;
}

int main()
{
	const char *a = "Hello world!";
	char dst[20] = {};
	const char *b = ft_strcpy(dst, a);
	printf("dst = %s %s\n", dst, b);
	printf("len = %d\n", ft_strlen(dst));

	printf("ft_strcmp = %d strcmp = %d\n", ft_strcmp(a, b), strcmp(a, b));
	printf("ft_strcmp = %d strcmp = %d\n", ft_strcmp(a, "Hello world  "), strcmp(a, "Hello world  "));

	printf("----\n");
	test_ft_write(4, "", 1);
	printf("----\n");
	test_ft_write(2, "Hi\n", 3);
	printf("----\n");
	test_ft_write(2, NULL, 1);
	return 0;
}