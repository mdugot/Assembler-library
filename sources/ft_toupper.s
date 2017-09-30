section .data

section .text
	global _ft_toupper

_ft_toupper:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 'a'
	jl other
	cmp rdi, 'z'
	jg other
up:
	mov rax, rdi
	sub rax, 0x20 
	leave
	ret
other:
	mov rax, rdi
	leave
	ret
	
