;	char	*strcpy(char * dst, const char * src);
;	rdi		#1 argument
;	rsi		#2

section .text
	global _ft_strcpy

_ft_strcpy:
		mov		rax,	0							;	count = 0
.again:	cmp		BYTE [rsi + rax],	0				;	while (dst[count])
		mov		dl,	BYTE [rsi + rax]
		mov		BYTE [rdi + rax], dl				;		dst[count] = src[count];
		je		.return
		inc		rax									;		count++
		jmp		.again

.return	mov		rax,	rdi
		ret

	; rax - returned register
