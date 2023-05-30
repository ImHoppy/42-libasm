global ft_strcmp

ft_strcmp: ; rdi ; rsi
	mov		al, BYTE [rdi]	; Seperate each byte of rdi in al
	mov		bl, BYTE [rsi]	; Seperate each byte of rsi in bl
	cmp		al, 0			; Check if al is not null
	je		exit
	cmp		bl, 0			; Check if bl is not null
	je		exit
	cmp		al, bl			; If al - bl is != of 0
	jne		return
	inc		rdi				; Increment rdi of one byte
	inc		rsi				; Increment rsi of one byte
	jmp		ft_strcmp		; Loop until *rdi or *rsi is null

exit:
	mov		rax, 0
	ret

return:
	mov		rax, 0
	movzx	rax, al			; Convert al (8 bits to 64 bits) to return register
	movzx	r8, bl			; Convert bl (8 bits to 64 bits) to trash register
	sub		rax, r8			; Subtract al with bl and store return value into rax
	ret
