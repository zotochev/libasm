;ssize_t	write(int fildes, const void *buf, size_t nbyte);

section .text
			global _ft_write
			extern ___error

_ft_write:
			mov			rax,	0x2000004 	;syscall write
			syscall
;			push		rax
			jc			_error
;			pop			rax
			ret

_error:		push		r12
			mov			r12,		rax
			call		___error
			mov			[rax],	r12
			pop			r12
			mov			rax,	-1
			ret

