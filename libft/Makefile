# Set compiler info
CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra -g

# Set directories
DIR_BASE			=	.
DIR_SOURCE			=	$(DIR_BASE)
DIR_OBJECT			=	$(DIR_BASE)
DIR_HEADER			=	$(DIR_BASE)
DIR_BONUS_SOURCE	=	$(DIR_BASE)
DIR_BONUS_OBJECT	=	$(DIR_BASE)

# Set source files
FILES_SOURCES		=	\
					$(DIR_SOURCE)/ft_atoi.c \
					$(DIR_SOURCE)/ft_bzero.c \
					$(DIR_SOURCE)/ft_calloc.c \
					$(DIR_SOURCE)/ft_isalnum.c \
					$(DIR_SOURCE)/ft_isalpha.c \
					$(DIR_SOURCE)/ft_isascii.c \
					$(DIR_SOURCE)/ft_isdigit.c \
					$(DIR_SOURCE)/ft_isprint.c \
					$(DIR_SOURCE)/ft_itoa.c \
					$(DIR_SOURCE)/ft_memchr.c \
					$(DIR_SOURCE)/ft_memcmp.c \
					$(DIR_SOURCE)/ft_memcpy.c \
					$(DIR_SOURCE)/ft_memmove.c \
					$(DIR_SOURCE)/ft_memset.c \
					$(DIR_SOURCE)/ft_putchar_fd.c \
					$(DIR_SOURCE)/ft_putendl_fd.c \
					$(DIR_SOURCE)/ft_putnbr_fd.c \
					$(DIR_SOURCE)/ft_putstr_fd.c \
					$(DIR_SOURCE)/ft_split.c \
					$(DIR_SOURCE)/ft_strchr.c \
					$(DIR_SOURCE)/ft_strdup.c \
					$(DIR_SOURCE)/ft_striteri.c \
					$(DIR_SOURCE)/ft_strjoin.c \
					$(DIR_SOURCE)/ft_strlcat.c \
					$(DIR_SOURCE)/ft_strlcpy.c \
					$(DIR_SOURCE)/ft_strlen.c \
					$(DIR_SOURCE)/ft_strmapi.c \
					$(DIR_SOURCE)/ft_strncmp.c \
					$(DIR_SOURCE)/ft_strnstr.c \
					$(DIR_SOURCE)/ft_strrchr.c \
					$(DIR_SOURCE)/ft_strtrim.c \
					$(DIR_SOURCE)/ft_substr.c \
					$(DIR_SOURCE)/ft_tolower.c \
					$(DIR_SOURCE)/ft_toupper.c \

FILES_BONUS_SOURCES	=	\
					$(DIR_BONUS_SOURCE)/ft_lstadd_back_bonus.c \
					$(DIR_BONUS_SOURCE)/ft_lstadd_front_bonus.c \
					$(DIR_BONUS_SOURCE)/ft_lstclear_bonus.c \
					$(DIR_BONUS_SOURCE)/ft_lstdelone_bonus.c \
					$(DIR_BONUS_SOURCE)/ft_lstiter_bonus.c \
					$(DIR_BONUS_SOURCE)/ft_lstlast_bonus.c \
					$(DIR_BONUS_SOURCE)/ft_lstmap_bonus.c \
					$(DIR_BONUS_SOURCE)/ft_lstnew_bonus.c \
					$(DIR_BONUS_SOURCE)/ft_lstsize_bonus.c \

FILE_HEADER			=	libft.h

# Set object files
FILES_OBJECTS		=	$(patsubst $(DIR_SOURCE)/%.c, $(DIR_OBJECT)/%.o, $(FILES_SOURCES))
FILES_BONUS_OBJECTS	=	$(patsubst $(DIR_BONUS_SOURCE)/%.c, $(DIR_BONUS_OBJECT)/%.o, $(FILES_BONUS_SOURCES))

# Set targets
NAME				=	libft.a

$(NAME): $(FILE_OBJECTS) $(FILE_HEADER)
	ar -rcs $@ $^

$(DIR_OBJECT)/%.o: $(DIR_SOURCE)/%.c | $(DIR_OBJECT)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(DIR_HEADER)

$(DIR_BONUS_OBJECT)/%.o: $(DIR_BONUS_SOURCE)/%.c | $(DIR_BONUS_OBJECT)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(DIR_HEADER)

$(DIR_OBJECT):
	mkdir -p $@

$(DIR_BONUS_OBJECT):
	mkdir -p $@

bonus:	$(FILES_OBJECTS) $(FILES_BONUS_OBJECTS)
	ar -rcs $(NAME) $(FILES_OBJECTS) $(FILES_BONUS_OBJECTS) $(FILE_HEADER)

all: $(NAME)

clean:
ifneq ($(DIR_OBJECT), $(DIR_BASE))
	rm -r $(DIR_OBJECT)
else
	rm -f $(FILES_OBJECTS)
endif
ifneq ($(DIR_BONUS_OBJECT), $(DIR_BASE))
	rm -r $(DIR_BONUS_OBJECT)
else
	rm -f $(FILES_BONUS_OBJECTS)
endif

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus