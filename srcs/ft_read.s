section	.text						;rdi, rsi, rdx, rcx, r8, r9
	global	ft_read					;read(fd, &buff, size)
	extern	__errno_location

ft_read:
	mov rax, 0
	syscall
	test rax, rax
	js handle_error
	ret

handle_error:
	neg	rax
	mov rdi, rax
	call __errno_location	WRT ..plt
	mov [rax], rdi
	mov rax, -1
	ret
