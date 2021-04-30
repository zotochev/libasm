;	int	strcmp(const char *s1, const char *s2);
;	rdi		#1 аргумент
;	rsi		#2

section .text
			global 	_ft_strcmp

_ft_strcmp:
			xor		rax,	rax							;	count = 0
.again:
			xor		rdx,	rdx					;	rdx = 0
			xor		rcx,	rcx					;	rcx = 0
			mov		dl,		[rdi + rax]			; 	dl  <	rdx
			mov		cl,		[rsi + rax]			;	cl	<	rcx

			cmp		rdx,	0
			jz		.process
			cmp		rcx,	0
			jz		.process
			cmp		rdx,	rcx
			jne		.process					; s1[count] != s2[count]

			inc		rax							;		count++
			jmp		.again

.process	xor		rax,	rax
			sub		rdx, 	rcx
			mov		rax, 	rdx
			ret
