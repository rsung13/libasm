;section .data
	;text db "" 

section .text					;rdi, rsi, rdx, rcx, r8, r9
	global ft_write				;write(fd, &buff, size)
	extern __errno_location

ft_write:
	mov rax, 1
	;mov rdi, rdi
	;mov rsi, rsi
	;mov rdx, rdx			not mandatory in this case
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
	 
