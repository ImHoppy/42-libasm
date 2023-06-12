#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	char *data;
	struct s_list *next;
} t_list;

void ft_list_push_front(t_list **, void *);
int ft_list_size(t_list *begin_list);

void printf_list(t_list *list)
{
	while (list)
	{
		printf("; %s\n", list->data);
		list = list->next;
	}
}

int main()
{
	t_list list;
	t_list list_next;
	t_list list_last;
	list.data = strdup("toto");
	list.next = &list_next;
	list_next.data = strdup("bar");
	list_next.next = &list_last;
	list_last.data = strdup("monkaS");
	list_last.next = NULL;

	int size = ft_list_size(&list);
	printf_list(&list);
	printf("new list size: %d \n", size);
	return 0;
	printf("\n--ft_list_push_front\n");
	t_list *push_test = &list;
	ft_list_push_front(&push_test, strdup("toto"));
	printf("added: `%s` (next: %p)\n", push_test->data, push_test->next);
	printf("new list size: %d (%d)\n", ft_list_size(push_test), 4);
	free(list.data);
	free(push_test->data);
	free(push_test);
	push_test = NULL;
	ft_list_push_front(&push_test, strdup("barbar"));
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	ft_list_push_front(&push_test, NULL);
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	free(push_test->next);
	push_test->next = NULL;
	ft_list_push_front(&push_test, strdup("toto_r"));
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	printf("-done\n");
}