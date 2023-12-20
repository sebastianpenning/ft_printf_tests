LIB_DIR := ../../ft_printf
LIB_ARC := libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf_c.c ft_printftests_utils.c ft_printftests.c 

OBJS = $(SRCS:.c=.o)

NAME = ft_printftests.a

.SILENT:

all: exe

exe: $(NAME)
	cc -Wall -Werror -Wextra ft_printftests.c ft_printftests.a && ./a.out
	rm a.out
	@$(MAKE) -s -C $(LIB_DIR) fclean

$(NAME): $(LIB_DIR)/$(LIB_ARC) $(OBJS) 
	ar rcs $(NAME) $(OBJS)

$(LIB_DIR)/$(LIB_ARC): 
	@$(MAKE) -s -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB_ARC) $(NAME)
	
 %.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@$(MAKE) -s -C $(LIB_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -s -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all
