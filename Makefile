NAME=minishell
LIBFTNAME=libft.a
CC=cc
CFLAGS=-Wall -Werror -Wextra -Ilibft -g3
LIBFLAGS= -lft -Llibft
LIBFTDIR = ./libft

SRC=    src/main.c \
		src/built_in/built_in1.c \
		src/built_in/add_histo_and_exec.c \
		src/built_in/ft_getenv.c \
		src/built_in/ft_export.c \
		src/built_in/ft_export_utils.c \
		src/built_in/ft_cd.c \
		src/built_in/ft_cd_utils.c \
		src/built_in/ft_cd_utils2.c \
		src/built_in/ft_echo.c \
		src/built_in/ft_env.c \
		src/built_in/ft_exit.c \
		src/built_in/ft_pwd.c \
		src/built_in/ft_unset.c \
		src/signal/signal.c \
		src/exec/exec.c \
		src/exec/type_builtin.c \
		src/exec/execute_parent_built.c \
		src/exec/exec_loop.c \
		src/exec/parsing.c \
		src/exec/path.c \
		src/exec/verif.c \
		src/exec/execute.c \
		src/exec/handle_cmd.c \
		src/exec/open_fd.c \
		src/exec/dup.c \
		src/exec/heredoc.c \
		src/exec/set_env.c \
		src/exec/first_cmd.c \
		src/exec/do_cmd.c \
		src/exec/mini_dup.c \
		src/utils/free.c \
		src/utils/close_pipe_fd.c \
		src/parsing/expand/expand_string.c \
		src/parsing/expand/expand_utils.c \
		src/parsing/expand/expand.c \
		src/parsing/fusion/fusion.c \
		src/parsing/fusion/main_function.c \
		src/parsing/lexer/create_linked_list.c \
		src/parsing/lexer/init_scanner.c \
		src/parsing/lexer/is_something.c \
		src/parsing/lexer/lexer.c \
		src/parsing/lexer/make_token.c \
		src/parsing/lexer/print_token.c \
		src/parsing/lexer/scan_scanner.c \
		src/parsing/parser/create_node.c \
		src/parsing/parser/handle.c \
		src/parsing/parser/parser_verif.c \
		src/parsing/parser/parser.c \
		src/parsing/parser/syntax_verif.c \
		src/parsing/lexer/ft_list_len.c \
		src/parsing/lexer/create_single_token.c \
		src/parsing/expand/expand_one_token_sub.c \
		src/parsing/expand/exp_one_tok_for_sub.c \
		src/parsing/expand/expand_one_token.c \
		src/parsing/parser/exit_parser.c \
		src/parsing/expand_inside_heredoc/exp_ins_heredoc.c

		

OBJ_DIR=obj
OBJS=$(SRC:%.c=$(OBJ_DIR)/%.o)

# Create necessary directories for .o files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFLAGS) -lreadline

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all

all: $(NAME)

default: all

.PHONY: all re clean fclean


# NAME = minishell
# LIBFTNAME = libft.a
# CC = cc

# CFLAGS = -Wall -Werror -Wextra -g3 -Ilibft -I/opt/homebrew/opt/readline/include
# LDFLAGS = -L/opt/homebrew/opt/readline/lib -lreadline

# LIBFTDIR = ./libft
# LIBFT = $(LIBFTDIR)/$(LIBFTNAME)

# SRC = \
# 	src/main.c \
# 	src/built_in/built_in1.c \
# 	src/built_in/ft_getenv.c \
# 	src/built_in/ft_export.c \
# 	src/built_in/ft_export_utils.c \
# 	src/built_in/ft_cd.c \
# 	src/built_in/ft_cd_utils.c \
# 	src/built_in/ft_cd_utils2.c \
# 	src/built_in/ft_echo.c \
# 	src/built_in/ft_env.c \
# 	src/built_in/ft_exit.c \
# 	src/built_in/ft_pwd.c \
# 	src/built_in/ft_unset.c \
# 	src/signal/signal.c \
# 	src/exec/exec.c \
# 	src/exec/exec_loop.c \
# 	src/exec/parsing.c \
# 	src/exec/path.c \
# 	src/exec/verif.c \
# 	src/exec/execute.c \
# 	src/exec/handle_cmd.c \
# 	src/exec/open_fd.c \
# 	src/exec/dup.c \
# 	src/exec/heredoc.c \
# 	src/exec/set_env.c \
# 	src/exec/first_cmd.c \
# 	src/exec/do_cmd.c \
# 	src/exec/mini_dup.c \
# 	src/utils/free.c \
# 	src/utils/close_pipe_fd.c \
# 	src/parsing/expand/expand_string.c \
# 	src/parsing/expand/expand_utils.c \
# 	src/parsing/expand/expand.c \
# 	src/parsing/fusion/fusion.c \
# 	src/parsing/fusion/main_function.c \
# 	src/parsing/lexer/create_linked_list.c \
# 	src/parsing/lexer/init_scanner.c \
# 	src/parsing/lexer/is_something.c \
# 	src/parsing/lexer/lexer.c \
# 	src/parsing/lexer/make_token.c \
# 	src/parsing/lexer/print_token.c \
# 	src/parsing/lexer/scan_scanner.c \
# 	src/parsing/parser/create_node.c \
# 	src/parsing/parser/handle.c \
# 	src/parsing/parser/parser_verif.c \
# 	src/parsing/parser/parser.c \
# 	src/parsing/parser/syntax_verif.c \
# 	src/parsing/lexer/ft_list_len.c \
# 	src/parsing/lexer/create_single_token.c

# OBJ_DIR = obj
# OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

# $(OBJ_DIR)/%.o: %.c
# 	@mkdir -p $(@D)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(NAME): $(OBJS)
# 	@make -C $(LIBFTDIR)
# 	$(CC) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

# clean:
# 	@rm -f $(OBJS)
# 	@rm -rf $(OBJ_DIR)
# 	@make -C $(LIBFTDIR) clean

# fclean: clean
# 	@rm -f $(NAME)
# 	@make -C $(LIBFTDIR) fclean

# re: fclean all

# all: $(NAME)

# .PHONY: all re clean fclean
