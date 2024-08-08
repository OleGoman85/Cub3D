# # Color Aliases
# DEFAULT = \033[0;39m
# GRAY = \033[0;90m
# RED = \033[0;91m
# GREEN = \033[0;92m
# YELLOW = \033[0;93m
# BLUE = \033[0;94m
# MAGENTA = \033[0;95m
# CYAN = \033[0;96m
# WHITE = \033[0;97m

# SHELL = /bin/bash
# UNAME = $(shell uname -s)

# # Path to MinilibX
# MLX_DIR = ./minilibx-linux

# # Properties for MacOS
# CDEBUG = #-g3 -fsanitize=address
# LMLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
# OS_X = -D OSX=1
# END = end_mac.c
# ifeq ($(UNAME), Linux)
# 	# Properties for Linux
# 	LEAKS = valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes -s -q 
# 	LMLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
# 	OS_X =
# 	END = end_linux.c
# 	CDEBUG = #-g3
# endif

# # Make variables
# PRINTF = printf
# CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)
# RM = rm -f
# CC = gcc -MD
# AR = ar rcs
# SRC_DIR = src
# OBJ_DIR = obj
# BIN_DIR = bin
# OBJ_GNL_DIR = obj_gnl
# BIN = cub3D
# NAME = $(BIN_DIR)/$(BIN)
# LIBFT = libft/bin/libft.a
# LIBFT_DIR = libft
# LIBFT_SRC = $(shell [ -d libft ] && ls libft/src*/*.c)
# GNL_DIR = get_next_line

# # Window Size
# WIDTH = 1080
# HEIGHT = 720
# WW = WIN_W=$(WIDTH)
# WH = WIN_H=$(HEIGHT)
# SZ = SIZE=10
# WIN_SIZE = -D $(WW) -D $(WH) -D $(SZ) $(OS_X)

# SRC_GNL = get_next_line.c get_next_line_utils.c

# SRC = main.c map.c error.c color.c	\
# 	  minimap.c raycast.c render.c	\
# 	  utils.c game.c my_mlx.c		\
# 	  parse_map.c textures.c 		\
# 	  player.c $(END)


# OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# OBJ_GNL = $(addprefix $(OBJ_GNL_DIR)/, $(SRC_GNL:.c=.o))

# # Progress vars
# SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
# ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
# 	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
# endif
# SRC_COUNT := 0
# SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))
# SRC_GNL_COUNT_TOT := $(shell expr $(shell echo -n $(SRC_GNL) | wc -w) - $(shell ls -l $(OBJ_GNL_DIR) 2>&1 | grep ".o" | wc -l) + 1)
# ifeq ($(shell test $(SRC_GNL_COUNT_TOT) -le 0; echo $$?),0)
# 	SRC_GNL_COUNT_TOT := $(shell echo -n $(SRC_GNL) | wc -w)
# endif
# SRC_GNL_COUNT := 0
# SRC_GNL_PCT = $(shell expr 100 \* $(SRC_GNL_COUNT) / $(SRC_GNL_COUNT_TOT))

# all: $(NAME)

# $(NAME): $(LIBFT) $(OBJ) $(OBJ_GNL) | $(BIN_DIR)
# 	@$(CC) $(CFLAGS) $(CDEBUG) $(OBJ) $(OBJ_GNL) $(LIBFT) $(LMLX) -lm -o $@
# 	@$(PRINTF) "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(GNL_DIR)
# 	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
# 	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
# 	@$(CC) $(CFLAGS) $(CDEBUG) $(WIN_SIZE) -I$(MLX_DIR) -c $< -o $@

# $(OBJ_GNL_DIR)/%.o: $(GNL_DIR)/%.c | $(OBJ_GNL_DIR)
# 	@$(eval SRC_GNL_COUNT = $(shell expr $(SRC_GNL_COUNT) + 1))
# 	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(MAGENTA)$<$(DEFAULT)..." "" $(SRC_GNL_COUNT) $(SRC_GNL_COUNT_TOT) $(SRC_GNL_PCT)
# 	@$(CC) $(CFLAGS) $(CDEBUG) $(WIN_SIZE) -I$(MLX_DIR) -c $< -o $@

# bonus: all

# $(LIBFT): $(LIBFT_SRC) | $(LIBFT_DIR) $(BIN_DIR)
# 	@make all -C libft
# 	@$(AR) $(NAME) $@

# test: all
# 	@$(PRINTF) "$(YELLOW)Performing test with custom map...$(DEFAULT)\n\n"
# 	@$(PRINTF) "Command: $(GRAY)$(LEAKS)./$(NAME) $(MAP)$(DEFAULT)\n\n"
# 	@$(LEAKS)./$(NAME) $(MAP)

# clean: | $(LIBFT_DIR)
# 	@$(PRINTF) "$(CYAN)Cleaning up object files in $(BIN)...$(DEFAULT)\n"
# 	@make clean -C libft
# 	@$(RM) -r $(OBJ_DIR)
# 	@$(RM) -r $(OBJ_GNL_DIR)

# fclean: clean | $(LIBFT_DIR)
# 	@$(RM) $(LIBFT)
# 	@$(PRINTF) "$(CYAN)Removed $(LIBFT)$(DEFAULT)\n"
# 	@$(RM) -r $(BIN_DIR)
# 	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

# norminette: | $(LIBFT_DIR) $(GNL_DIR)
# 	@make norminette -C libft
# 	@$(PRINTF) "$(CYAN)\nChecking norm for get_next_line...$(DEFAULT)\n"
# 	@norminette -R CheckForbiddenSourceHeader $(GNL_DIR)
# 	@$(PRINTF) "$(CYAN)\nChecking norm for $(BIN)...$(DEFAULT)\n"
# 	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) inc/

# $(OBJ_DIR):
# 	@mkdir -p $(OBJ_DIR)

# $(OBJ_GNL_DIR):
# 	@mkdir -p $(OBJ_GNL_DIR)

# $(BIN_DIR):
# 	@mkdir -p $(BIN_DIR)

# $(LIBFT_DIR):
# 	@git clone https://gitlab.com/madebypixel02/libft.git

# $(GNL_DIR):
# 	@git clone https://gitlab.com/madebypixel02/get_next_line.git

# re: fclean
# 	@make all

# git:
# 	git add .
# 	git commit
# 	git push

# -include $(OBJ_DIR)/*.d
# -include $(OBJ_GNL_DIR)/*.d

# .PHONY: all clean fclean bonus norminette test play git re




#////////// rabochaja versija ///////

# # Основные настройки
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# LMLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

# # Директории и файлы
# SRC_DIR = src
# OBJ_DIR = obj
# BIN_DIR = bin
# BIN = cub3D
# NAME = $(BIN_DIR)/$(BIN)
# LIBFT = libft/bin/libft.a
# LIBFT_DIR = libft
# LIBFT_SRC = $(shell [ -d libft ] && ls libft/src*/*.c)
# GNL_DIR = get_next_line

# # Исходные файлы
# SRC_GNL = get_next_line.c get_next_line_utils.c
# SRC = main.c map.c error.c color.c	\
# 	  minimap.c raycast.c render.c	\
# 	  utils.c game.c my_mlx.c		\
# 	  parse_map.c textures.c 		\
# 	  player.c end_linux.c

# # Объектные файлы
# OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
# OBJ_GNL = $(addprefix $(OBJ_DIR)/, $(SRC_GNL:.c=.o))

# # Основная цель
# all: $(NAME)

# # Сборка исполняемого файла
# $(NAME): $(LIBFT) $(OBJ) $(OBJ_GNL) | $(BIN_DIR)
# 	$(CC) $(CFLAGS) $(OBJ) $(OBJ_GNL) $(LIBFT) $(LMLX) -o $@

# # Компиляция исходных файлов в объектные
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(GNL_DIR)
# 	$(CC) $(CFLAGS) -Iminilibx-linux -c $< -o $@

# # Сборка библиотеки libft
# $(LIBFT): $(LIBFT_SRC) | $(LIBFT_DIR) $(BIN_DIR)
# 	make -C libft
# 	ar rcs $(NAME) $@

# # Создание директорий, если они не существуют
# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)

# $(BIN_DIR):
# 	mkdir -p $(BIN_DIR)

# # Очистка
# clean:
# 	make clean -C libft
# 	rm -rf $(OBJ_DIR)

# # Полная очистка
# fclean: clean
# 	rm -f $(NAME)
# 	rm -rf $(BIN_DIR)

# # Пересборка
# re: fclean all

# # Подключение зависимостей
# -include $(OBJ_DIR)/*.d

# .PHONY: all clean fclean re




# # Основные настройки
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# LMLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

# # Директории и файлы
# SRC_DIR = src
# OBJ_DIR = $(SRC_DIR)
# NAME = cub3D
# LIBFT = libft/bin/libft.a
# LIBFT_DIR = libft
# LIBFT_SRC = $(shell [ -d libft ] && ls libft/src*/*.c)
# GNL_DIR = get_next_line

# # Исходные файлы
# SRC_GNL = get_next_line.c get_next_line_utils.c
# SRC = main.c map.c error.c color.c	\
# 	  minimap.c raycast.c render.c	\
# 	  utils.c game.c my_mlx.c		\
# 	  parse_map.c textures.c 		\
# 	  player.c end_linux.c

# # Объектные файлы
# OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
# OBJ_GNL = $(SRC_GNL:%.c=$(OBJ_DIR)/%.o)

# # Основная цель
# all: $(NAME)

# # Сборка исполняемого файла
# $(NAME): $(LIBFT) $(OBJ) $(OBJ_GNL)
# 	$(CC) $(CFLAGS) $(OBJ) $(OBJ_GNL) $(LIBFT) $(LMLX) -o $@

# # Компиляция исходных файлов в объектные
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(GNL_DIR)
# 	$(CC) $(CFLAGS) -Iminilibx-linux -c $< -o $@

# # Сборка библиотеки libft
# $(LIBFT): $(LIBFT_SRC) | $(LIBFT_DIR)
# 	make -C libft

# # Создание директорий, если они не существуют
# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)

# # Очистка
# clean:
# 	make clean -C libft
# 	rm -f $(OBJ_DIR)/*.o

# # Полная очистка
# fclean: clean
# 	rm -f $(NAME)

# # Пересборка
# re: fclean all

# # Подключение зависимостей
# -include $(OBJ_DIR)/*.d

# .PHONY: all clean fclean re



# Основные настройки
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# LMLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

# # Директории и файлы
# SRC_DIR = src
# NAME = cub3D
# LIBFT = libft/bin/libft.a
# LIBFT_DIR = libft
# LIBFT_SRC = $(shell [ -d libft ] && ls libft/src*/*.c)
# GNL_DIR = get_next_line

# # Исходные файлы
# SRC_GNL = get_next_line.c get_next_line_utils.c
# SRC = main.c map.c error.c color.c	\
# 	  minimap.c raycast.c render.c	\
# 	  utils.c game.c my_mlx.c		\
# 	  parse_map.c textures.c 		\
# 	  player.c end_linux.c

# # Объектные файлы для GNL
# OBJ_GNL = $(addprefix $(GNL_DIR)/, $(SRC_GNL:.c=.o))

# # Основные объектные файлы
# OBJ = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

# # Основная цель
# all: $(NAME)

# # Сборка исполняемого файла
# $(NAME): $(LIBFT) $(OBJ) $(OBJ_GNL)
# 	$(CC) $(CFLAGS) $(OBJ) $(OBJ_GNL) $(LIBFT) $(LMLX) -o $@

# # Компиляция исходных файлов в объектные
# $(SRC_DIR)/%.o: $(SRC_DIR)/%.c | $(GNL_DIR)
# 	$(CC) $(CFLAGS) -Iminilibx-linux -c $< -o $@

# # Компиляция файлов GNL в объектные
# $(GNL_DIR)/%.o: $(GNL_DIR)/%.c | $(GNL_DIR)
# 	$(CC) $(CFLAGS) -Iminilibx-linux -c $< -o $@

# # Сборка библиотеки libft
# $(LIBFT): $(LIBFT_SRC) | $(LIBFT_DIR)
# 	make -C libft

# # Очистка
# clean:
# 	make clean -C libft
# 	rm -f $(SRC_DIR)/*.o
# 	rm -f $(GNL_DIR)/*.o

# # Полная очистка
# fclean: clean
# 	rm -f $(NAME)

# # Пересборка
# re: fclean all

# # Подключение зависимостей
# -include $(SRC_DIR)/*.d

# .PHONY: all clean fclean re




#poslednjaja rabochaja

# # Основные настройки
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# LMLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

# # Имя исполняемого файла
# NAME = cub3D

# # Библиотека libft
# LIBFT = libft/libft.a

# # Директории исходных файлов
# SRC_DIR = src
# GNL_DIR = get_next_line
# LIBFT_DIR = libft

# # Исходные файлы
# SRC_GNL = get_next_line.c get_next_line_utils.c
# SRC = main.c map.c error.c color.c \
#       minimap.c raycast.c render.c \
#       utils.c game.c my_mlx.c \
#       parse_map.c textures.c \
#       player.c end_linux.c

# # Объектные файлы для GNL
# OBJ_GNL = $(SRC_GNL:%.c=$(GNL_DIR)/%.o)

# # Объектные файлы для основных файлов
# OBJ = $(SRC:%.c=$(SRC_DIR)/%.o)

# # Основная цель
# all: $(NAME)

# # Сборка исполняемого файла
# $(NAME): $(LIBFT) $(OBJ) $(OBJ_GNL)
# 	$(CC) $(CFLAGS) $(OBJ) $(OBJ_GNL) $(LIBFT) $(LMLX) -o $@

# # Компиляция исходных файлов в объектные (для GNL)
# $(GNL_DIR)/%.o: $(GNL_DIR)/%.c | $(GNL_DIR)
# 	$(CC) $(CFLAGS) -Iminilibx-linux -Ilibft -c $< -o $@

# # Компиляция исходных файлов в объектные (для основных файлов)
# $(SRC_DIR)/%.o: $(SRC_DIR)/%.c | $(SRC_DIR)
# 	$(CC) $(CFLAGS) -Iminilibx-linux -Ilibft -c $< -o $@

# # Создание директорий, если они не существуют
# # $(GNL_DIR):
# # 	mkdir -p $(GNL_DIR)

# # $(SRC_DIR):
# # 	mkdir -p $(SRC_DIR)

# # Сборка библиотеки libft
# $(LIBFT):
# 	make -C $(LIBFT_DIR)

# # Очистка
# clean:
# 	make -C $(LIBFT_DIR) clean
# 	rm -f $(OBJ) $(OBJ_GNL)

# # Полная очистка
# fclean: clean
# 	make -C $(LIBFT_DIR) fclean
# 	rm -f $(NAME)

# # Пересборка
# re: fclean all

# .PHONY: all clean fclean re


CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LMLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

# Имя исполняемого файла
NAME = cub3D

# Библиотека libft
LIBFT = libft/libft.a

# Директории исходных файлов
SRC_DIR = src
GNL_DIR = get_next_line
LIBFT_DIR = libft

BGreen=\033[1;32m
BRed=\033[1;31m

# Исходные файлы
SRC_GNL = get_next_line.c get_next_line_utils.c
SRC = main.c map.c error.c color.c \
      minimap.c raycast.c render.c \
      utils.c game.c my_mlx.c \
      map_checking.c textures.c \
      player.c end_linux.c

# Все исходные файлы
ALL_SRC = $(addprefix $(SRC_DIR)/, $(SRC)) $(addprefix $(GNL_DIR)/, $(SRC_GNL))

# Все объектные файлы
OBJ = $(ALL_SRC:.c=.o)

# Основная цель
all: tag $(NAME)

# Сборка исполняемого файла
$(NAME): $(LIBFT) $(OBJ) tag
	@echo "\n               $(BGreen)Building target file: $(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LMLX) -o $@ > /dev/null
	@echo "$(BGreen)                   🕹  LET'S BEGIN!!! 🎮"

# Компиляция исходных файлов в объектные
%.o: %.c
	@$(CC) $(CFLAGS) -Iminilibx-linux -Ilibft -c $< -o $@ > /dev/null

# Сборка библиотеки libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null

# Очистка
clean:
	@echo "$(BRed)Cleaning......"
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@$(RM) $(OBJ) .tag
	@echo "              ............ READY"

# Полная очистка
fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@$(RM) $(NAME)

# Пересборка
re: fclean all

.PHONY: all clean fclean re

tag:
	@if [ ! -e .tag ]; then \
		echo "$(BGreen)"; \
		echo "	██████╗ ██╗   ██╗██████╗ ██████╗ ██████╗"; \
		echo " 	██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗"; \
		echo "	██║     ██║   ██║██████╔╝ █████╔╝██║  ██║"; \
		echo "	██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║"; \
		echo "	╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝"; \
		echo "	╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ "; \
  		touch .tag; \
	fi        

                                
                                
