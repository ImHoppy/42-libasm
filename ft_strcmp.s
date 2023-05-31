global ft_strcmp

ft_strcmp: ; rdi ; rsi
	mov		r8b, BYTE [rdi]	; Seperate each byte of rdi in r8b
	mov		r9b, BYTE [rsi]	; Seperate each byte of rsi in r9b
	cmp		r8b, 0			; Check if r8b is not null
	je		return
	cmp		r9b, 0			; Check if r8b is not null
	je		return
	cmp		r8b, r9b			; If r8b - r9b is != of 0
	jne		return
	inc		rdi				; Increment rdi of one byte
	inc		rsi				; Increment rsi of one byte
	jmp		ft_strcmp		; Loop until *rdi or *rsi is null

return:
	movzx	rax, r8b			; Convert r8b (8 bits to 64 bits) to return register
	movzx	r10, r9b			; Convert r9b (8 bits to 64 bits) to trash register
	sub		rax, r10			; Subtract r8b with r9b and store return value into rax
	ret
