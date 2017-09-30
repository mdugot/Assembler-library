section .data

section .text
	global _ft_strcat

_ft_strcat:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	mov rax, rdi

go_end:
	cmp byte [rdi], 0
	je cat
	add rdi, 1
	jmp go_end

cat:
	cmp byte [rsi], 0
	je return
	mov bl, byte [rsi]
	mov byte [rdi], bl
	add rdi, 1
	add rsi, 1
	jmp cat

return:
	mov byte [rdi], 0
	leave
	ret
