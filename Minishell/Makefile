# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opaulman <opaulman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 17:07:05 by cdenaux           #+#    #+#              #
#    Updated: 2026/05/14 16:07:10 by opaulman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline

#Commande pour creer la bibliotheque
AR = ar rcs

#Commande pour supprimer les fichiers
RM = rm -f 

# Tous les fichiers sources (mandatory)
SRCS = 	main.c \
		Builtins/ft_echo.c \
		Builtins/ft_exit.c \
		Builtins/ft_pwd.c \
		Builtins/ft_env.c \
		Builtins/ft_unset.c \
		Builtins/ft_export.c \
		Builtins/ft_cd.c \
		Execution/check_do_cmd.c \
		Utils/init_env.c \
		Utils/cmd_utils.c \
		Utils/ft_lstsize.c\
		Parsing/ft_tokenizer.c\
		Parsing/ft_parser.c\

INCLUDE = -I. -I$(LIBFT_PATH)

LIBFT_PATH = ../Libft

LIBFT = $(LIBFT_PATH)/libft.a

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Fichier header
HEADER = minishell.h

# Regle par defaut
all: $(NAME)

# Creation de la bibliotheque
$(NAME): $(OBJS) $(LIBFT) 
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Compilation des fichiers objets
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

# Recompilation complete
re: fclean all

# Run with valgrind for memory leak detection
valgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
		--suppressions=readline.supp ./$(NAME)

# Declaration des regles qui ne sont pas des fichiers
.PHONY: all clean fclean re valgrind
