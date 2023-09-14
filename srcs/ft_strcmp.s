section	.text
	global ft_strcmp

ft_strcmp:
	mov	rax, 0

loop_str1:
	mov bl, [rdi + rax]
	mov cl, [rsi + rax]
	cmp bl, 0
	je	compare_str
	cmp bl, cl
	jne	compare_str
	inc	rax
	jmp loop_str1

compare_str:
	cmp bl, cl
	jl	less_end
	cmp bl, cl
	jg	greater_end
	;mov rax, 0
	;ret	another way of doing it
	cmp	bl, cl
	je	equal

less_end:
	sub bl, cl
	movsx rax, bl
	ret

greater_end:
	sub bl, cl
	movsx rax, bl
	ret

equal:
	mov rax, 0
	ret
