# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 17:07:05 by cdenaux           #+#    #+#              #
#    Updated: 2026/05/20 15:55:59 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lreadline

#Commande pour creer la bibliotheque
AR = ar rcs

#Commande pour supprimer les fichiers
RM = rm -f 

# Tous les fichiers sources (mandatory)
SRCS = 	main.c \
		Builtins/ft_cd.c \
		Builtins/ft_echo.c \
		Builtins/ft_env.c \
		Builtins/ft_exit.c \
		Builtins/ft_export.c \
		Builtins/ft_pwd.c \
		Builtins/ft_unset.c \
		Execution/ft_apply_redirs.c \
		Execution/ft_builtin.c \
		Execution/ft_execute.c \
		Execution/ft_heredoc.c \
		Expansion/ft_expand.c \
		Parsing/cmd_utils.c \
		Parsing/ft_parser.c \
		Parsing/ft_tokenizer.c \
		Utils/cmd_utils_v2.c \
		Utils/free_and_errors.c \
		Utils/free_lists.c \
		Utils/ft_listsizes.c \
		Utils/ft_shell_loop.c \
		Utils/init_env.c \

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
