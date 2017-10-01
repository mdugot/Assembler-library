section .data

section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cld
	mov rax, 0
	mov rcx, -1
	repne scasb
	mov rax, -1
	sub rax, rcx
	dec rax
	leave
	ret

