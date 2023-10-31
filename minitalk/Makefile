LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(CLIENT) $(SERVER)

$(SERVER): $(LIBFT) 
	cc $(SRCS_SERVER) libft/libft.a -o $@

$(CLIENT): $(LIBFT)
	cc $(SRCS_CLIENT) libft/libft.a -o $@

$(LIBFT):
		${MAKE} -C ./libft

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(SERVER) $(CLIENT)

re: fclean all