#	Compilation
CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra -g
MAKE				=	make

#	Directories
DIR_BASE			=	.
DIR_SOURCE			=	src
DIR_INCLUDE			=	include
DIR_LIBFT			=	libft
DIR_OBJECT			=	obj
DIR_BINARY			=	$(DIR_BASE)

#	Files
FILE_SOURCES		=	\
					$(DIR_SOURCE)/ft_declen.c \
					$(DIR_SOURCE)/ft_getaddr.c \
					$(DIR_SOURCE)/ft_getchar.c \
					$(DIR_SOURCE)/ft_getdec.c \
					$(DIR_SOURCE)/ft_getint.c \
					$(DIR_SOURCE)/ft_getlowhex.c \
					$(DIR_SOURCE)/ft_getnode_var.c \
					$(DIR_SOURCE)/ft_getnode.c \
					$(DIR_SOURCE)/ft_getstr.c \
					$(DIR_SOURCE)/ft_getudec.c \
					$(DIR_SOURCE)/ft_getupphex.c \
					$(DIR_SOURCE)/ft_lsttrypush.c \
					$(DIR_SOURCE)/ft_printf.c \
					$(DIR_SOURCE)/ft_tohexstr.c \
					$(DIR_SOURCE)/ft_varstr.c \

FILES_OBJECTS		=	$(patsubst $(DIR_SOURCE)/%.c, $(DIR_OBJECT)/%.o, $(FILE_SOURCES))
FILE_LIBFT			=	$(DIR_LIBFT)/libft.a
FILE_LIBFT_HEADER	=	$(DIR_LIBFT)/libft.h
FILE_HEADER			=	$(DIR_INCLUDE)/ft_printf.h

#	Targets
NAME				=	libftprintf.a
TARGET				=	$(DIR_BINARY)/$(NAME)

$(TARGET):	$(FILES_OBJECTS) $(FILE_LIBFT) | $(DIR_BINARY)
	ar -rcs $(TARGET) $(FILES_OBJECTS) $(FILE_LIBFT) $(FILE_HEADER) $(FILE_LIBFT_HEADER)

$(DIR_OBJECT)/%.o: $(DIR_SOURCE)/%.c | $(DIR_OBJECT)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(DIR_INCLUDE) -I$(DIR_LIBFT)

$(DIR_OBJECT):
	mkdir -p $@

$(DIR_BINARY):
	mkdir -p $@

$(FILE_LIBFT):
	$(MAKE) -C $(DIR_LIBFT) bonus

all:	$(TARGET)

clean:
	rm -rf $(FILES_OBJECTS)
	$(MAKE) -C $(DIR_LIBFT) clean

fclean: clean
	rm -rf $(TARGET)
	$(MAKE) -C $(DIR_LIBFT) fclean

re:	fclean all

.PHONY:	all clean fclean re