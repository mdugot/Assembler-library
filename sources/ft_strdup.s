section .data

section .text
	global _ft_strdup
	extern _malloc

_ft_strdup:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cld

	push rdi
	mov rax, 0
	mov rcx, -1
	repne scasb
	mov rdi, -1
	sub rdi, rcx
	push rdi
	call _malloc
	cmp rax, 0
	je error
	pop rcx
	pop rsi
	mov rdi, rax
	rep movsb

	leave
	ret
error:
	mov rax, 0
	leave
	ret

