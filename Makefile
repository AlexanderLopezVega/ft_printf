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
FILE_SOURCES		=	$(DIR_SOURCE)/ft_convert_char.c \
						$(DIR_SOURCE)/ft_convert_hex.c \
						$(DIR_SOURCE)/ft_convert_int.c \
						$(DIR_SOURCE)/ft_convert_ptr.c \
						$(DIR_SOURCE)/ft_convert_str.c \
						$(DIR_SOURCE)/ft_printf.c \
						$(DIR_SOURCE)/ft_putarg_fd.c
#						$(DIR_SOURCE)/ft_convert_dec.c
FILES_OBJECTS		=	$(patsubst $(DIR_SOURCE)/%.c, $(DIR_OBJECT)/%.o, $(FILE_SOURCES))
FILE_LIBFT			=	$(DIR_LIBFT)/libft.a
FILE_HEADER			=	$(DIR_INCLUDE)/ft_printf.h

#	Targets
NAME				=	libftprintf.a
TARGET				=	$(DIR_BINARY)/$(NAME)

$(TARGET):	$(FILES_OBJECTS) $(FILE_LIBFT) | $(DIR_BINARY)
	cp $(FILE_LIBFT) $(TARGET)
	ar -rcs $@ $< $(FILE_HEADER)

$(DIR_OBJECT)/%.o: $(DIR_SOURCE)/%.c $(FILE_LIBFT) $(FILE_LIBFT_INCLUDE) | $(DIR_OBJECT)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INCLUDE) -I $(DIR_LIBFT)

$(DIR_OBJECT):
	mkdir -p $@

$(DIR_BINARY):
	mkdir -p $@

$(FILE_LIBFT):
	$(MAKE) -C $(DIR_LIBFT) bonus

all:	$(TARGET)

clean:
	rm -rf $(DIR_OBJECT)
	$(MAKE) -C $(DIR_LIBFT) clean

fclean: clean
	rm -rf $(TARGET)
	$(MAKE) -C $(DIR_LIBFT) fclean

re:	fclean all

.PHONY:	all clean fclean re