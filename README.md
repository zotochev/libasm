# libasm

## Description
Small library on assembly language (intel x86)
implemented following functions:
```
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);
```

## Build
**requirements**: nasm, gcc, make

To build run `make` in the root of the project. This will create small library `libasm.a` written on assembly language (intel x86)

## Tests
To see how library `libasm.a` works I prepared some tests in directry `tests`.

To run tests run `make tests` in the root of the project
