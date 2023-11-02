LIBFT = libft/libft.a
LIBFTPRINTF = libft/ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
SERVER_B = server_bonus
CLIENT_B = client_bonus
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c
RUN = libft/libft.a libft/ft_printf/libftprintf.a

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all: $(CLIENT) $(SERVER)

$(SERVER): $(OBJS_SERVER) $(LIBFT) $(LIBFTPRINTF)
	@cc $(OBJS_SERVER) $(RUN) -o $@
	@echo "server created"

$(CLIENT): $(OBJS_CLIENT) $(LIBFT) $(LIBFTPRINTF)
	@cc $(OBJS_CLIENT) $(RUN) -o $@
	@echo "client created"

$(LIBFT):
	@${MAKE} -C ./libft > /dev/null

$(LIBFTPRINTF):
	@${MAKE} -C ./libft/ft_printf > /dev/null

bonus: $(CLIENT_B) $(SERVER_B)

$(SERVER_B): $(OBJS_SERVER_BONUS) $(LIBFT) $(LIBFTPRINTF)
	@cc $(OBJS_SERVER_BONUS) $(RUN) -o $@
	@echo "server created_bonus"

$(CLIENT_B): $(OBJS_CLIENT_BONUS) $(LIBFT) $(LIBFTPRINTF)
	@cc $(OBJS_CLIENT_BONUS) $(RUN) -o $@
	@echo "client_bonus created"

clean:
	@$(MAKE) clean -C ./libft > /dev/null
	@$(MAKE) clean -C ./libft/ft_printf > /dev/null
	@rm -rf $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	@echo "objects removed"

fclean: clean
	@$(MAKE) fclean -C ./libft > /dev/null
	@$(MAKE) fclean -C ./libft/ft_printf > /dev/null
	@rm -rf $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	@echo "server and client removed"

re: fclean all
