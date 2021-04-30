NAME		=	libasm.a
HEADER		=	libasm.h
HEADER_TEST	=	libasm_unit_tests.h

SRC_C	=	$(addprefix libasm_unit_tests/,	\
						main.c				\
						ft_strlen_test.c	\
						ft_strcpy_test.c	\
						ft_strcmp_test.c	\
						ft_write_test.c		\
						ft_read_test.c		\
						ft_strdup_test.c	\
						get_test_array.c	\
						)

SRC_S	=	$(addprefix srcs/,				\
						ft_strlen.s			\
						ft_strcpy.s			\
						ft_strcmp.s			\
						ft_write.s			\
						ft_read.s			\
						ft_strdup.s			\
						)

OBJ_C		=	$(SRC_C:.c=.o)
OBJ_S		=	$(SRC_S:.s=.o)

CFLAGS		=	-Wall -Wextra -Werror -Ilibasm_unit_tests -Iincludes

CC			=	gcc

VPATH		=	libasm_unit_tests

.PHONY:	all clean fclean re
all:		$(NAME)

$(NAME):	$(OBJ_S) includes/$(HEADER) Makefile
			ar rc $@ $(OBJ_S)
			ranlib $@

test:		$(NAME) $(OBJ_C) $(HEADER_TEST) Makefile
			$(CC) $(CFLAGS) -o $@ $(OBJ_C) $(NAME)
			./test

%.o			:%.c $(HEADER) $(HEADER_TEST)

%.o			:%.s
			nasm -f macho64 -o $@ $<

clean:
			-rm -f $(OBJ_C) $(OBJ_S)
			-rm -rf test_file_sys test_file_lib

fclean:		clean
			-rm -f $(NAME)
			-rm -f test

re:			fclean all

