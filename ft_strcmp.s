global ft_strcmp

ft_strcmp: ; rdi ; rsi
	cmp		BYTE rdi, 0
	je		exit
	cmp		BYTE rsi, 0
	je		exit

	inc		rdi
	inc		rsi
	jmp		ft_strcmp


exit:
	mov		rax, 0
	ret