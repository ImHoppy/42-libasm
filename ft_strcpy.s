global ft_strcpy
ft_strcpy:						; rdi = dest ; rsi = src
	mov		rcx, 0x0
	jmp loop_cpy

loop_cpy:
	cmp		BYTE [rsi + rcx], 0x0	; rsi[rcx] == '\0'
	je		return				; Break loop if condition is true
	mov		cl, [rsi + rcx]		; Get src char at rcx
	mov		[rdi + rcx], cl		; Cpy char from rsi[rcx] at rdi[rcx]
	inc		rcx					; Increment rcx
	jmp		loop_cpy

return:
	mov		cl, 0x0				; Set '\0' to cl
	mov		[rdi + rcx], cl		; Terminate rdi by NULL byte
	mov 	rax, rdi			; Move rdi to rax as return value
	ret
