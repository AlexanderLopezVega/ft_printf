#	Compilation
CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra -g
MAKE				=	make

#	Directories
DIR_BASE			=	.
DIR_SOURCES			=	src
DIR_INCLUDES		=	include
DIR_LIBFT			=	libft
DIR_OBJECTS			=	obj
DIR_BINARIES		=	$(DIR_BASE)

#	Files
FILE_SOURCES		=	\
					$(DIR_SOURCES)/ft_declen.c \
					$(DIR_SOURCES)/ft_getaddr.c \
					$(DIR_SOURCES)/ft_getchar.c \
					$(DIR_SOURCES)/ft_getdec.c \
					$(DIR_SOURCES)/ft_getint.c \
					$(DIR_SOURCES)/ft_getlowhex.c \
					$(DIR_SOURCES)/ft_getstr.c \
					$(DIR_SOURCES)/ft_getudec.c \
					$(DIR_SOURCES)/ft_getupphex.c \
					$(DIR_SOURCES)/ft_printf.c \
					$(DIR_SOURCES)/ft_tohexstr.c \

FILE_OBJECTS		=	$(patsubst $(DIR_SOURCES)/%.c, $(DIR_OBJECTS)/%.o, $(FILE_SOURCES))
FILE_LIBFT			=	$(DIR_LIBFT)/libft.a

#	Targets
NAME				=	libftprintf.a
TARGET				=	$(DIR_BINARIES)/$(NAME)

$(TARGET):	$(FILE_OBJECTS) $(FILE_LIBFT) | $(DIR_BINARIES)
	ar -rcs $(TARGET) $(FILE_OBJECTS) $(FILE_LIBFT)

$(DIR_OBJECTS)/%.o: $(DIR_SOURCES)/%.c | $(DIR_OBJECTS)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(DIR_INCLUDES) -I$(DIR_LIBFT)

$(DIR_OBJECTS):
	mkdir -p $@

$(DIR_BINARIES):
	mkdir -p $@

$(FILE_LIBFT):
	$(MAKE) -C $(DIR_LIBFT) bonus

all:	$(TARGET)

clean:
	rm -rf $(FILE_OBJECTS)
	cd $(DIR_LIBFT)
	$(MAKE) -C $(DIR_LIBFT) clean

fclean: clean
	rm -rf $(TARGET)
	cd $(DIR_LIBFT)
	$(MAKE) -C $(DIR_LIBFT) fclean

re:	fclean all

.PHONY:	all clean fclean re