#include <stdio.h>

typedef struct s_list
{
	void *data;
	struct s_list *next;
} t_list;

void ft_list_push_front(t_list **, void *);

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
	list.data = ft_strdup("toto");
	list.next = &list_next;
	list_next.data = ft_strdup("bar");
	list_next.next = &list_last;
	list_last.data = ft_strdup("monkaS");
	list_last.next = NULL;

	t_list *list_parent = &list;

	printf("\n--ft_list_sort\n");
	ft_list_push_front(&list_parent, strdup("zwxy"));
	ft_list_push_front(&list_parent, strdup("toto"));
	ft_list_push_front(&list_parent, strdup("0123456"));
	ft_list_push_front(&list_parent, strdup("barbar"));
	ft_list_push_front(&list_parent, strdup("rooooom"));
	ft_list_push_front(&list_parent, strdup("lol"));
	ft_list_push_front(&list_parent, strdup("tortor"));
	ft_list_push_front(&list_parent, strdup("mdr"));
	ft_list_push_front(&list_parent, strdup("0547"));
	ft_list_push_front(&list_parent, strdup("000"));
	ft_list_push_front(&list_parent, strdup("zzz"));
	printf("-done\n");
	printf_list(list_parent);
}