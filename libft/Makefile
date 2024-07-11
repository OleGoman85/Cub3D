
# librari name
NAME = libft.a

# compailing
CC = cc

# flags
CFLAGS = -Wall -Wextra -Werror

# list of files
SRC_FILES = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_strlen.c ft_memset.c \
ft_bzero.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_strnstr.c ft_atoi.c \
ft_calloc.c ft_strdup.c ft_isprint.c ft_memcmp.c ft_memcpy.c ft_isdigit.c \
ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \
ft_realloc.c ft_strcmp.c ft_epur_str.c ft_first_word.c ft_inter.c ft_last_word.c \
ft_max.c ft_realloc.c ft_rev_print.c ft_rev_wstr.c ft_search_and_replace.c \
ft_sort_int_tab.c ft_strcmp.c ft_strcspn.c ft_strpbrk.c ft_strrev.c ft_strspn.c \
ft_swap.c ft_union.c ft_free_matrix.c ft_strrncmp.c ft_extend_matrix.c \
ft_matrixlen.c ft_countchar.c ft_newvector.c ft_lstnew.c ft_lstadd_back.c

# from .c to .o
OBJ_FILES = $(SRC_FILES:.c=.o)

BONUS_FILES = ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ_BONUS = $(BONUS_FILES:.c=.o)

all: $(NAME)

# Building the library
$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean clean_bonus
	rm -f $(NAME)

re: fclean all

#BONUS

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

clean_bonus:
	rm -f $(OBJ_BONUS)

.PHONY: all clean fclean re bonus

