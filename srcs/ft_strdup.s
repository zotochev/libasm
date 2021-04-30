;	char	*strdup(const char *s1);

section .text
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy
	global	_ft_strdup

_ft_strdup:
	call	_ft_strlen
	push	rdi

	mov		rdi, rax
	call	_malloc

	cmp		rax, 0			;	if (NULL == rax)
	jz		_error			;		return (NULL);

	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy
	ret

_error:		ret
