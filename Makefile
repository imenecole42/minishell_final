
.PHONY : all clean fclean re

NAME := minishell.a
SOFT_NAME := minishell

CC := gcc
FLAGS := -Wall -Wextra -Werror -lreadline -g -I includes/
SRC_DIR := sources/
OBJ_DIR := objects/
AR := ar rc
RM := rm

BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

SRCS =	main.c \
		create_env.c \
		create_export.c \
		echo.c \
		export.c \
		expand.c \
		free.c\
		ft_exit.c \
		ft_free.c \
		util_export.c \
		util_print_export.c \
		unset.c \
		ft_pwd.c \
		ft_cd.c   \
		ft_expo.c \
		init.c \
		input_utils.c \
		lexer.c \
		lexer_utils.c \
		parser.c \
		parsing_utils.c \
		basic_functions.c\
		execution.c \
		close_exec.c \
		ft_free_exec.c \
		ft_child.c \
		util_exec.c \
		ft_is_bullting.c \
		
		


LIBFT := Libft/libft.a
FCLIB := ${MAKE} fclean -C Libft

OBJS = $(SRCS:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR),$(OBJS))

OBJF := .cache_exists

all : ${LIBFT} ${SOFT_NAME}

${LIBFT} :
	${MAKE} all -C Libft

${OBJ_DIR}%.o : %.c | $(OBJF)
	@echo "${BLUE}###${NC}Creation du fichier ${@:%.c=%.o}${BLUE}###${ORANGE}"
	${CC} ${FLAGS} -c $< -o $@
	@echo "${NC}"

${SOFT_NAME} : ${OBJ}
	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_NAME}${BLUE}###${MAGENTA}"
	${CC} ${OBJ} ${FLAGS} ${LIBFT} -o ${SOFT_NAME}
	@echo "${NC}"

$(OBJF) :
	@mkdir -p ${OBJ_DIR}

clean : 
	${FCLIB}
	@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
	${RM} -rf ${OBJ_DIR}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

fclean : clean
	@echo "${RED}###${NC}Nettoyage d'archives et de Softs${RED}###"
	${RM} -f ${NAME} ${SOFT_NAME}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

re : fclean all
