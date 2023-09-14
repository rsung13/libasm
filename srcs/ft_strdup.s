section	.text						;rdi, rsi, rdx, rcx, r8, r9
	global	ft_strdup				;strdup(str)
	extern	__errno_location
	extern	malloc
	extern	ft_strlen
	extern	ft_strcpy

ft_strdup:
	call	ft_strlen
	mov		r8, rdi
	inc		rax
	mov		rdi, rax
	call	malloc	WRT ..plt
	test	rax, rax
	jz		handle_error
	mov		rdi, rax
	mov		rsi, r8
	call	ft_strcpy
	
	ret

handle_error:
	call	__errno_location	WRT ..plt
	mov		r9, 12
	mov		[rax], r9
	mov		rax, 0
	ret
