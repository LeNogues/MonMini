# Nom de la bibliothèque
NAME = libft.a

# Fichiers sources
SRCS = ft_split.c \
       ft_putnbr_fd.c \
       ft_strtrim.c \
       ft_strmapi.c \
       ft_strnstr.c \
       ft_putchar_fd.c  \
       ft_strncmp.c \
       ft_putendl_fd.c  \
       ft_strrchr.c \
       ft_atoi.c \
       ft_putstr_fd.c \
       ft_substr.c \
       ft_bzero.c \
       ft_strchr.c \
       ft_tolower.c \
       ft_calloc.c \
       ft_strdup.c \
       ft_strndup.c \
       ft_toupper.c \
       ft_isalnum.c \
       ft_memchr.c \
       ft_striteri.c \
       ft_isalpha.c \
       ft_memcmp.c \
       ft_strjoin.c \
       ft_isascii.c \
       ft_memcpy.c \
       ft_strlcat.c \
       ft_isdigit.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_isprint.c \
       ft_memset.c \
       ft_strlen.c \
       printf.c \
       utils_char.c \
       utils_number.c \
       ft_lstmap_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstlast_bonus.c \
       ft_tablen.c \
       ft_free_tab.c \
       ft_atol.c \
       ft_strtok.c \
       ft_itoa.c

OBJS = $(SRCS:.c=.o)

# Fichiers sources pour les bonus




# Compilateur et options de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Commandes de Makefile
all: $(NAME)

# Compilation de la bibliothèque statique
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation des fichiers objets bonus

# Nettoyage des objets
clean:
	rm -f $(OBJS)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
