global ft_write
; rax 	System call 	rdi 				rsi 		rdx
; 1 	sys_write 		#filedescriptor 	$buffer 	#count
ft_write:
	mov		rax, 1
	syscall 				; Call sus_write
	ret