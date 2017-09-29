section .data
nl:
	db 10
null:
	.str db "(null)", 10
	.len equ $ - null.str

section .text
	global _ft_puts

_ft_puts:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	cmp rdi, 0
	je _print_null
	mov rsi, rdi
	mov rdi, 1
	call _get_len
	mov rax, 0x2000004
	syscall
	mov rdi, 1
	mov rsi, nl
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	mov rax, 0xa
	leave
	ret

_get_len:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rdx, 0
_loop:
	cmp byte [rsi+rdx], 0
	je _return
	jne _inc
_return:
	leave
	ret
_inc:
	add rdx, 1
	jmp _loop

_print_null:
	mov rdi, 1
	mov rsi, null.str
	mov rdx, null.len
	mov rax, 0x2000004
	syscall
	mov rax, 0xa
	leave
	ret
