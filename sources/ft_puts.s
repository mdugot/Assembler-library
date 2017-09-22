section .data
hello:
	.string db "Hello World!", 10
	.len equ $ - hello.string

section .text
	global start
	global _test
	extern _printf

_test:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	lea rdi, [rel hello.string]
	call _printf
	leave
	ret
