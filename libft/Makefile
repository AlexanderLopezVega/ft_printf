# Set compiler info
CC			=	cc
CFLAGS				=	-Wall -Werror -Wextra -g

# Set directories
BSE_DIR		=	.
SRC_DIR		=	$(BSE_DIR)
OBJ_DIR		=	$(BSE_DIR)
HDR_DIR		=	$(BSE_DIR)
BNS_SRC_DIR	=	$(BSE_DIR)
BNS_OBJ_DIR	=	$(BSE_DIR)

# Set source files
SRCS		=	\
				$(SRC_DIR)/ft_atoi.c \
				$(SRC_DIR)/ft_bzero.c \
				$(SRC_DIR)/ft_calloc.c \
				$(SRC_DIR)/ft_isalnum.c \
				$(SRC_DIR)/ft_isalpha.c \
				$(SRC_DIR)/ft_isascii.c \
				$(SRC_DIR)/ft_isdigit.c \
				$(SRC_DIR)/ft_isprint.c \
				$(SRC_DIR)/ft_itoa.c \
				$(SRC_DIR)/ft_memchr.c \
				$(SRC_DIR)/ft_memcmp.c \
				$(SRC_DIR)/ft_memcpy.c \
				$(SRC_DIR)/ft_memmove.c \
				$(SRC_DIR)/ft_memset.c \
				$(SRC_DIR)/ft_putchar_fd.c \
				$(SRC_DIR)/ft_putendl_fd.c \
				$(SRC_DIR)/ft_putnbr_fd.c \
				$(SRC_DIR)/ft_putstr_fd.c \
				$(SRC_DIR)/ft_split.c \
				$(SRC_DIR)/ft_strchr.c \
				$(SRC_DIR)/ft_strdup.c \
				$(SRC_DIR)/ft_striteri.c \
				$(SRC_DIR)/ft_strjoin.c \
				$(SRC_DIR)/ft_strlcat.c \
				$(SRC_DIR)/ft_strlcpy.c \
				$(SRC_DIR)/ft_strlen.c \
				$(SRC_DIR)/ft_strmapi.c \
				$(SRC_DIR)/ft_strncmp.c \
				$(SRC_DIR)/ft_strnstr.c \
				$(SRC_DIR)/ft_strrchr.c \
				$(SRC_DIR)/ft_strtrim.c \
				$(SRC_DIR)/ft_substr.c \
				$(SRC_DIR)/ft_tolower.c \
				$(SRC_DIR)/ft_toupper.c \

BNS_SRCS	=	\
				$(BNS_SRC_DIR)/ft_lstadd_back_bonus.c \
				$(BNS_SRC_DIR)/ft_lstadd_front_bonus.c \
				$(BNS_SRC_DIR)/ft_lstclear_bonus.c \
				$(BNS_SRC_DIR)/ft_lstdelone_bonus.c \
				$(BNS_SRC_DIR)/ft_lstiter_bonus.c \
				$(BNS_SRC_DIR)/ft_lstlast_bonus.c \
				$(BNS_SRC_DIR)/ft_lstmap_bonus.c \
				$(BNS_SRC_DIR)/ft_lstnew_bonus.c \
				$(BNS_SRC_DIR)/ft_lstsize_bonus.c \

# Set object files
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
BNS_OBJS	=	$(patsubst $(BNS_SRC_DIR)/%.c, $(BNS_OBJ_DIR)/%.o, $(BNS_SRCS))

# Set targets
NAME		=	libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus:	$(BNS_OBJS) $(NAME)
	ar -rcs $(NAME) $(OBJS) $(BNS_OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HDR_DIR)

$(BNS_OBJ_DIR)/%.o: $(BNS_SRC_DIR)/%.c | $(BNS_OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HDR_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(BNS_OBJ_DIR):
	mkdir -p $@

clean:
ifneq ($(OBJ_DIR), $(BSE_DIR))
	rm -r $(OBJ_DIR)
else
	rm -f $(OBJS)
endif
ifneq ($(BNS_OBJ_DIR), $(BSE_DIR))
	rm -r $(BNS_OBJ_DIR)
else
	rm -f $(BNS_OBJS)
endif

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus