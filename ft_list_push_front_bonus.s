global ft_list_push_front

extern malloc

; t_list = { .data = void*, .next = t_list* }

ft_list_push_front: ; rdi = t_list **begin_list, rsi = void *data
	push	rsi					; Save pointer data
	push	rdi					; Save pointer list
	mov		rdi, 16				; rdi = sizeof(t_list) = 16
	call	malloc wrt ..plt	; Alloc the new elem list
	pop		rdi					; Get saved list
	pop		rsi					; Get saved data
	cmp		rax, 0				; Check if malloc return 0
	je		return				; 	-> return
	mov		[rax], rsi			; new.data = data
	mov		rcx, [rdi]			; rcx = *begin_list
	mov		[rax + 8], rcx		; new.next = *begin_list
	mov		[rdi], rax			; *begin_list = new

return:
	ret
