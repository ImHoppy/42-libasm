#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "colors.h"
#include "libasm.h"

#define PRINT_OLD_NEW(OLD_LABEL, NEW_LABEL, OLD, NEW) printf(OLD_LABEL ": (s" COLOR_VALUE("%s") ", p" COLOR_VALUE("%p") ", l" COLOR_VALUE("%d") ")\n" NEW_LABEL ": (s" COLOR_VALUE("%s") ", p" COLOR_VALUE("%p") ", l" COLOR_VALUE("%d") ")\n", \
															 OLD, OLD, ft_strlen(OLD), NEW, NEW, ft_strlen(NEW))

#define PRINT_STRCMP(L, R) printf("ft_strcmp = " COLOR_VALUE("%d") "; strcmp = " COLOR_VALUE("%d") "\n", \
								  ft_strcmp(L, R), strcmp(L, R))

#define PRINT_WRITE(FUN, RET) printf(FUN " = " COLOR_VALUE("%d") ", errno = " COLOR_VALUE("%d") "\n", RET, errno)

void test_ft_write(int fd, char *b, size_t len)
{
	const int ret_write = write(fd, b, len);
	PRINT_WRITE("write\t", ret_write);
	errno = 0;
	const int ret_ft_write = ft_write(fd, b, len);
	PRINT_WRITE("ft_write", ret_ft_write);
	errno = 0;
}

#define PRINT_READ(FUN, RET, BUF) printf(FUN " = " COLOR_VALUE("%d") ", errno = " COLOR_VALUE("%d") ", buf = " COLOR_VALUE("%s") "\n", RET, errno, BUF)

void test_ft_read(int fd, char *buf, size_t count)
{
	const int ret_read = read(fd, buf, count);
	PRINT_READ("read\t", ret_read, buf);
	errno = 0;
	const int ret_ft_read = ft_read(fd, buf, count);
	PRINT_READ("ft_read\t", ret_ft_read, buf);
	errno = 0;
}

int main()
{
	const char *hw = "Hello world!";
	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!"));
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
	printf(BLK "\n## Compare with one char missing\n" CRESET);
	PRINT_STRCMP("Hello world#", "Hello world");

	printf(BLU "\n# ft_write\n" CRESET);
	printf(BLK "\n## Wrong fd\n" CRESET);
	test_ft_write(4, "", 1);
	printf(BLK "\n## Normal write\n" CRESET);
	test_ft_write(2, "Hi\n", 3);
	printf(BLK "\n## Null buffer write\n" CRESET);
	test_ft_write(2, NULL, 1);

	printf(BLU "\n# ft_read\n" CRESET);
	printf(BLK "## Please enter two times the same string\n" CRESET);
	char buf[64];
	printf(BLK "\n## Wrong fd\n" CRESET);
	test_ft_read(3, buf, 63);
	printf(BLK "\n## Normal read\n" CRESET);
	test_ft_read(0, buf, 63);
	printf(BLK "\n## Null buffer read\n" CRESET);
	test_ft_read(0, NULL, 63);
	return 0;
}