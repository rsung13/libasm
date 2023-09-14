section	.text
	global ft_strcpy

ft_strcpy:
	mov rax, 0

loop_src:
	mov bl, [rsi + rax]
	mov [rdi + rax], bl
	cmp bl, 0
	je end
	inc rax
	jmp loop_src

end:
	mov rax, rdi
	ret
