LIBFT = libft/libft.a
LIBFTPRINTF = libft/ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
RUN = libft/libft.a libft/ft_printf/libftprintf.a

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(CLIENT) $(SERVER)

$(SERVER): $(OBJS_SERVER) $(LIBFT) $(LIBFTPRINTF)
	cc $(SRCS_SERVER) $(RUN) -o $@

$(CLIENT): $(OBJS_CLIENT) $(LIBFT) $(LIBFTPRINTF)
	cc $(SRCS_CLIENT) $(RUN) -o $@

$(LIBFT):
		${MAKE} -C ./libft

$(LIBFTPRINTF):
		${MAKE} -C ./libft/ft_printf

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./libft/ft_printf
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./libft/ft_printf
	rm -rf $(SERVER) $(CLIENT)

re: fclean all
