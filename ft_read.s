global ft_read
extern __errno_location
; rax	System call		rdi					rsi			rdx
; 0		sys_read		#filedescriptor		$buffer		#count
ft_read:
	mov		rax, 0
	syscall 								; Call sys_read
	cmp		rax, 0							; Compare return of sys_read with 0
	jl		return_error					; Jump to return_error if rax < 0
	ret										; return sys_read output

return_error:
	mov		r8, rax							; Save errno
	call	__errno_location wrt ..plt		; Get ptr of errno.
	neg		r8								; set errno as positive
	mov		[rax], r8						; Set return value of write into *errno
	mov		rax, -1							; return -1
	ret