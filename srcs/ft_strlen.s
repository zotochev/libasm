; size_t	strlen(const char *s);

section .text
	global _ft_strlen

_ft_strlen:
		mov		rax,	0				;	count = 0
.again:	cmp		BYTE [rdi + rax],	0	;	while (line[count])
		je		.return
		inc		rax						;	count++
		jmp		.again

.return	ret

	; rax - returned register
