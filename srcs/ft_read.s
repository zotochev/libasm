;ssize_t	read(int fildes, void *buf, size_t nbyte);

section .text
			global _ft_read
			extern ___error

_ft_read:
			mov			rax,	0x2000003 	;syscall read
			syscall	
			jc			_error
			ret

_error:		push		r8
			mov			r8,		rax
			call		___error
			mov			[rax],	r8
			pop			r8
			mov			rax,	-1
			ret
