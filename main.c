#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "colors.h"

#define COLOR_VALUE(S) "`" GRN S CRESET "`"

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

#define PRINT_OLD_NEW(OLD_LABEL, NEW_LABEL, OLD, NEW) printf(OLD_LABEL ": (s" COLOR_VALUE("%s") ", p" COLOR_VALUE("%p") ", l" COLOR_VALUE("%d") ")\n" NEW_LABEL ": (s" COLOR_VALUE("%s") ", p" COLOR_VALUE("%p") ", l" COLOR_VALUE("%d") ")\n", \
															 OLD, OLD, ft_strlen(OLD), NEW, NEW, ft_strlen(NEW))

#define PRINT_STRCMP(L, R) printf("ft_strcmp = " COLOR_VALUE("%d") "; strcmp = " COLOR_VALUE("%d") "\n", \
								  ft_strcmp(L, R), strcmp(L, R))

int main()
{
	const char *hw = "Hello world!";
	printf(BLU "\n# ft_strdup\n" CRESET);
	char *new = ft_strdup(hw);
	PRINT_OLD_NEW("old", "new", hw, new);
	free(new);

	printf(BLU "\n# ft_strcpy\n" CRESET);
	char *dst = malloc(ft_strlen(hw) * sizeof(char));
	const char *cpy = ft_strcpy(dst, hw);
	PRINT_OLD_NEW("src", "dst", hw, dst);

	printf(BLU "\n# ft_strcmp\n" CRESET);
	printf(BLK "\n## Compare with cpy\n" CRESET);
	PRINT_STRCMP(hw, cpy);
	printf(BLK "\n## Compare with one char different\n" CRESET);
	PRINT_STRCMP(hw, "Hello world  ");
	PRINT_STRCMP("Hello world#", "Hello world$");

	// getchar();
	// test_ft_write(4, "", 1);
	// test_ft_write(2, "Hi\n", 3);
	// test_ft_write(2, NULL, 1);

	// getchar();
	// char buf[64];
	// test_ft_read(3, buf, 63);
	// test_ft_read(0, buf, 63);
	// test_ft_read(0, NULL, 63);
	return 0;
}