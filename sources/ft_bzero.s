section .data

section .text
	global _ft_bzero

_ft_bzero:
	push rbp
	mov rbp, rsp
	sub rsp, 16

zero:
	cmp rsi, 0
	jle end
	mov byte [rdi], 0
	add rdi, 1
	sub rsi, 1
	jmp zero

end:
	leave
	ret
