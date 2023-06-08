NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CHECKER_DIR = src/checker
LIBFT_DIR = ft_printf/libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
INCLUDES = -I . -I include -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR)

COMMON_SRCS = src/stack/stack.c src/stack/push.c src/stack/rotate.c src/stack/reverse_rotate.c src/stack/swap.c src/stack/sort.c src/stack/errors.c src/stack/scan.c src/stack/free.c src/stack/print.c src/stack/getters.c src/stack/big_sort_utils.c src/stack/optimiser.c
PUSH_SWAP_SRCS = $(COMMON_SRCS) src/main.c
CHECKER_SRCS = $(COMMON_SRCS) $(CHECKER_DIR)/checker.c $(CHECKER_DIR)/get_next_line/get_next_line.c $(CHECKER_DIR)/get_next_line/get_next_line_utils.c
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME)

push_swap: $(PUSH_SWAP_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(PUSH_SWAP_OBJS) $(LIBFT) $(FT_PRINTF) -o push_swap

checker: $(CHECKER_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(CHECKER_OBJS) $(LIBFT) $(FT_PRINTF) -o checker

bonus: $(NAME) checker

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) checker
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
