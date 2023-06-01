global ft_list_push_front

extern malloc

ft_list_push_front: ; rdi = t_list **begin_list, rsi = void *data
	cmp		rdi, 0
	je		init
	call	alloc_list
	mov		[rax+8], [rdi]

init:
	call	alloc_list
	call	exit

alloc_list:
	push	rdi
	mov		rdi, 1
	call	malloc
	cmp		rax, 0
	je		exit
	pop		rdi
	mov		[rax], rsi		; set data
	mov		[rax+8], 0		; set next

exit:
	ret
