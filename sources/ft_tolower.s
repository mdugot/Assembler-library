section .data

section .text
	global _ft_tolower

_ft_tolower:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 'A'
	jl other
	cmp rdi, 'Z'
	jg other
low:
	mov rax, rdi
	add rax, 0x20 
	leave
	ret
other:
	mov rax, rdi
	leave
	ret

