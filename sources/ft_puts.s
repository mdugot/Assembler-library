section .data

section .text
	global _ft_puts

_ft_puts:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rsi, rdi
	mov rdi, 1
	call _get_len
	mov rax, 0x2000004
	syscall
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
