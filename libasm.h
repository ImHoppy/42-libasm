#ifndef LIBASM_H
#define LIBASM_H

#include <sys/types.h>

size_t ft_strlen(const char *);
char *ft_strcpy(char *, const char *);
int ft_strcmp(const char *, const char *);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);

#ifdef BONUS

typedef struct s_list
{
	char *data;
	struct s_list *next;
} t_list;

void ft_list_push_front(t_list **, void *);
int ft_list_size(t_list *begin_list);

#endif // BONUS

#endif // LIBASM_H