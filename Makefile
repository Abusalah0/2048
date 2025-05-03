CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Iinclude 
NAME = 2048

LIBFT_DIR = libft
LDFLAGS = -L$(LIBFT_DIR) -lft -lreadline -lncurses
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
OBJS_DIR = objs

SRC = main.c random_spawn.c start_game.c init.c drawing.c key_events.c events.c game_loop.c signal_handler.c colors.c menu.c utils.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re