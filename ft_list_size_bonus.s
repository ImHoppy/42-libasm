global ft_list_size

ft_list_size: ; rdi = t_list *begin_list
	xor		rax, rax
	jmp		loop

loop:
	cmp		rdi, 0
	jne		return
	inc		rax
	mov		rdi, [rdi + 8]

return:
	ret
