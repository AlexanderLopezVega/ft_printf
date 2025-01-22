#	Compilation
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
MAKE			=	make

#	Directories
DIR_SOURCES		=	src
DIR_INCLUDES	=	include
DIR_OBJECTS		=	obj
DIR_BINARIES	=	.

#	Files
FILES_SOURCES	=	\
					ft_printf.c \
FILES_OBJECTS	=	$($(FILES_SOURCES):.c=.o)

#	Targets
NAME			=	libftprintf.a
TARGET			=	$(DIR_BINARIES)/$(NAME)

libft:
	$(MAKE) -C libft

$(TARGET):	$(FILES_OBJECTS)
	ar -rcs $(TARGET) $(FILES_OBJECTS) -I $(DIR_INCLUDES)

$(DIR_OBJECTS)/%.o: $(DIR_SOURCES)/%.c
	$(CC) $(CFLAGS) -c $@ -o $<

all:	$(NAME)

clean:
	rm -rf $(FILES_OBJECTS)

fclean:
	rm -rf $(TARGET)

re:	fclean all

.PHONY:	all clean fclean re