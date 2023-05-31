#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int ft_strlen(const char *);
char *ft_strcpy(char *, const char *);
int ft_strcmp(const char *, const char *);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);

void test_ft_write(int fd, char *b, size_t len)
{
	printf("----\n");

	const int ret_write = write(fd, b, len);
	printf("write %d, errno = %d\n", ret_write, errno);
	errno = 0;
	const int ret_ft_write = ft_write(fd, b, len);
	printf("ft_write %d, errno = %d\n", ret_ft_write, errno);
	errno = 0;
}

void test_ft_read(int fd, char *buf, size_t count)
{
	printf("----\n");

	const int ret_read = read(fd, buf, count);
	printf("read %d, errno = %d\n", ret_read, errno);
	errno = 0;
	const int ret_ft_read = ft_read(fd, buf, count);
	printf("ft_read %d, errno = %d\n", ret_ft_read, errno);
	errno = 0;
}

int main()
{
	const char *a = "Hello world!";
	char *new = ft_strdup(a);
	printf("%p %p %s\n", a, new, new);
	free(new);
	return 0;

	char dst[20] = {};
	const char *b = ft_strcpy(dst, a);
	printf("dst = %s %s\n", dst, b);
	printf("len = %d\n", ft_strlen(dst));

	getchar();
	printf("ft_strcmp = %d strcmp = %d\n", ft_strcmp(a, b), strcmp(a, b));
	printf("ft_strcmp = %d strcmp = %d\n", ft_strcmp(a, "Hello world  "), strcmp(a, "Hello world  "));

	getchar();
	test_ft_write(4, "", 1);
	test_ft_write(2, "Hi\n", 3);
	test_ft_write(2, NULL, 1);

	getchar();
	char buf[64];
	test_ft_read(3, buf, 63);
	test_ft_read(0, buf, 63);
	test_ft_read(0, NULL, 63);
	return 0;
}