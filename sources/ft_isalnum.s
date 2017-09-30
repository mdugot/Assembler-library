section .data

section .text
	global _ft_isalnum

_between:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, rsi
	jl false
	cmp rdi, rdx
	jg false
	jmp true

_ft_isalnum:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	mov rsi, 'a'
	mov rdx, 'z'
	call _between
	cmp rax, 0
	jne true

	mov rsi, 'A'
	mov rdx, 'Z'
	call _between
	cmp rax, 0
	jne true

	mov rsi, '0'
	mov rdx, '9'
	call _between
	cmp rax, 0
	jne true

false:
	mov rax, 0x0
	leave
	ret
true:
	mov rax, 0x1
	leave
	ret

