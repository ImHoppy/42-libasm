global ft_write
extern __errno_location
; rax 	System call 	rdi 				rsi 		rdx
; 1 	sys_write 		#filedescriptor 	$buffer 	#count

ft_write:
	mov		rax, 1
	syscall 								; Call sus_write, return errno in negative.
	cmp		rax, 0							; Compare return of sys_write with 0
	jl		return_error					; Jump to return_error if rax < 0
	ret										; return sys_write output

return_error:
	mov		r8, rax							; Save errno
	call	__errno_location wrt ..plt		; Get ptr of errno, "wrt ..plt" alow write on readonly variale
	neg		r8								; set errno as positive
	mov		[rax], r8						; Set return value of write into *errno
	mov		rax, -1							; return -1
	ret