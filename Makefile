LIB_DIR := ft_printf
LIB_ARC := libft_printf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf_c.c ft_printftests_utils.c ft_printftests.c 

OBJS = $(SRCS:.c=.o)

NAME = ft_printftests.a

all: $(NAME) 

$(NAME): $(LIB_DIR)/$(LIB_ARC) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIB_DIR)/$(LIB_ARC): 
	@$(MAKE) -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB_ARC) $(NAME).a
	
 %.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all
