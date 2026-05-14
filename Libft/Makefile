# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdenaux <cdenaux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 17:07:05 by cdenaux           #+#    #+#              #
#    Updated: 2026/01/14 08:46:48 by cdenaux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

#Commande pour creer la bibliotheque
AR = ar rcs

#Commande pour supprimer les fichiers
RM = rm -f

#Fichiers sources - Part 1 (fonctions libc)
SRCS_PART1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			 ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
			 ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			 ft_atoi.c ft_calloc.c

# Fichiers sources - Part 2 (fonctions additionnelles)
SRCS_PART2 = ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c \
			 ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			 ft_putendl_fd.c ft_putnbr_fd.c	

# Fichiers sources - Get Next Line
SRCS_GNL = get_next_line.c get_next_line_utils.c \

# Tous les fichiers sources (mandatory)
SRCS = $(SRCS_PART1) $(SRCS_PART2) $(SRCS_GNL)

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Fichier header
HEADER = libft.h

# Regle par defaut
all: $(NAME)

# Creation de la bibliotheque
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compilation des fichiers objets
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	$(RM) $(OBJS)

# Nettoyage complet
fclean: clean
	$(RM) $(NAME)

# Recompilation complete
re: fclean all

# Declaration des regles qui ne sont pas des fichiers
.PHONY: all bonus clean fclean re
