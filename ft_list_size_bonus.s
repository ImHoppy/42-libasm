global ft_list_size

ft_list_size: ; rdi = t_list *begin_list
	mov		rsi, rdi            ; Save pointer list
	xor		rax, rax			; Set rax to 0
	jmp		loop				; Start loop

loop:
	cmp		rdi, 0				; if (rdi == NULL)
	je		return				;	-> return rax
	inc		rax					; rax++
	mov		rdi, [rdi + 8]		; Move rdi->next to rdi
	jmp		loop

return:
	mov		rdi, rsi            ; Return saved pointer
	ret
