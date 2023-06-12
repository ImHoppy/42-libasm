global ft_strdup

extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:						; rdi = src
	push	rdi					; save str for later
	call	ft_strlen			; get length of str
	inc		rax					; len + 1 for \0 end
	mov		rdi, rax			; rdi = str length
	call	malloc wrt ..plt	; malloc(rdi)
	cmp		rax, 0				; if malloc return == NULL
	je		failure				;  > return NULL
	mov		rdi, rax			; rdi = new_str
	pop		rsi					; rsi = str
	call	ft_strcpy			; ft_strcpy(rdi, rsi)
	ret

failure:
	pop		rdi					; clean
	mov		rax, 0				; retrn 0
	ret