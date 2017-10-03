%define SYSCALL(n) 0x2000000 | n
%define SIZE 0x1000
%define RS qword [rsp]
%define FD qword [rsp + 16]
%define BUFF [rsp + 32]

section .data
msg:
	.str db "cat: Bad file descriptor", 10
	.len equ $ - msg.str

section .text
	global _ft_cat

_ft_cat:
	push rbp
	mov rbp, rsp
	sub rsp, SIZE
	sub rsp, 32

	mov FD, rdi

read:
	mov rdi, FD
	lea rsi, BUFF
	mov rdx, SIZE
	mov rax, SYSCALL(3)
	syscall

	jc error

	mov RS, rax
	mov rdi, 1
	lea rsi, BUFF
	mov rdx, RS
	mov rax, SYSCALL(4)
	syscall

	cmp RS, 0
	jne read
	
end:
	mov rsp, rbp
	pop rbp
	ret
	
error:
	mov rdi, 2
	lea rsi, [rel msg.str]
	mov rdx, msg.len
	mov rax, SYSCALL(4)
	syscall
	mov rsp, rbp
	pop rbp
	ret
