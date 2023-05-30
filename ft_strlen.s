global ft_strlen

ft_strlen:
	mov		rax, 0		; i = 0
	jmp		loop_count  ; jump to loop_count function

loop_count:
	cmp		BYTE [rdi + rax], 0 ; check if str + i == 0
	je		return				; jump to return if cmp return is 1
	inc		rax					; i++
	jmp		loop_count			; jump loop_count

return:
	ret							; return i