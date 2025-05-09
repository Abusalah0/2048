CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude
NAME = libft.a

SRC_DIR = src
OBJS_DIR = objs

SRC =  	int_ops/ft_atoi.c \
		int_ops/ft_atol.c \
		int_ops/ft_tolower.c \
		int_ops/ft_toupper.c \
		int_ops/ft_itoa.c \
		int_ops/ft_isspace.c \
		int_ops/ft_atod.c \
		int_ops/ft_isalnum.c \
		int_ops/ft_isalpha.c \
		int_ops/ft_isascii.c \
		int_ops/ft_isdigit.c \
		int_ops/ft_isprint.c \
		int_ops/ft_is_pow_of_2.c \
		int_ops/ft_isnumber.c \
		int_ops/ft_count_digits.c \
		memory/ft_bzero.c \
		memory/ft_calloc.c \
		memory/ft_memchr.c  \
		memory/ft_memcmp.c  \
		memory/ft_memcpy.c  \
		memory/ft_memmove.c \
		memory/ft_memset.c \
		string/ft_strchr.c \
		string/ft_split.c \
		string/ft_strdup.c \
		string/ft_strjoin.c \
		string/ft_strlcat.c \
		string/ft_strlcpy.c \
		string/ft_strlen.c \
		string/ft_strncmp.c \
		string/ft_strnstr.c \
		string/ft_strrchr.c \
		string/ft_substr.c \
		string/ft_strtrim.c \
		string/ft_strmapi.c \
		string/ft_striteri.c \
		string/ft_strcmp.c \
		string/ft_strncpy.c \
		string/ft_strcpy.c \
		string/ft_str_replace.c \
		print/ft_putchar_fd.c \
		print/ft_putstr_fd.c \
		print/ft_putendl_fd.c \
		print/ft_putnbr_fd.c \

BONUS = linked_lst/ft_lstadd_back_bonus.c \
		linked_lst/ft_lstadd_front_bonus.c \
		linked_lst/ft_lstclear_bonus.c \
		linked_lst/ft_lstdelone_bonus.c \
		linked_lst/ft_lstiter_bonus.c \
		linked_lst/ft_lstlast_bonus.c \
		linked_lst/ft_lstmap_bonus.c \
		linked_lst/ft_lstnew_bonus.c \
		linked_lst/ft_lstsize_bonus.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
BONUS_SRCS = $(addprefix $(SRC_DIR)/, $(BONUS))

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
BONUS_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJS_DIR)/%.o, $(BONUS_SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus