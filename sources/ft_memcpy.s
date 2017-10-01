section .data

section .text
	global _ft_memcpy

_ft_memcpy:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cld
	push rdi
	mov rcx, rdx
	rep movsb
	pop rax
	leave
	ret
