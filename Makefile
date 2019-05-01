# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osfally <osfally@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 09:21:23 by osfally           #+#    #+#              #
#    Updated: 2019/05/01 00:11:52 by osfally          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# executable name
CHECKER		:=	checker
PUSHSWAP	:=	push_swap

# directories
SRC_DIR		:=	./srcs
INC_DIR		:=	./includes
OBJ_DIR		:=	./obj
LIB_DIR		:=	./libft

# libraries
LIB_INC		:=	$(LIB_DIR)/includes
LIB_EXC		:=	$(LIB_DIR)/libft.a
LIB_OBJ		:=	$(LIB_DIR)/obj

# src / obj files
CHCK		:=	checker.c
PSWP		:=	push_swap.c
SRCS		:=	stack.c\
				helpers.c\
				instructions.c\

OBJS		:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJ_CHCK	:=	$(addprefix $(OBJ_DIR)/, $(CHCK:.c=.o))
OBJ_PSWP	:=	$(addprefix $(OBJ_DIR)/, $(PSWP:.c=.o))

INCS		:=	-I $(INC_DIR)\
				-I $(LIB_INC)

# compiler and flags
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
DFLAGS		:=	-fsanitize=address -g

# uncomment to debug
# CFLAGS		+=	DFLAGS

.PHONY: all clean fclean re

all: mkdirectory  $(CHECKER)

# create the obj folder
mkdirectory: $(LIB_EXC)
	@mkdir -p $(OBJ_DIR)

$(LIB_EXC):
	@$(MAKE) -C $(LIB_DIR) >/dev/null || make

# create object files in the obj folder
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCS) -o $@ -c $<
	@echo "Object created."

$(CHECKER): $(OBJS) $(OBJ_CHCK)
	@$(CC) $(CFLAGS) $(OBJS) $(OBJ_CHCK) $(INCS) $(LIB_EXC) -o $(CHECKER)
	@echo "Executable created: $(CHECKER)"

# clean obj folder
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects cleaned."

# clean obj folder and executable
fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo "Executable and library cleaned."

# renew obj folder and executable
re: fclean all

# CLEANCLEANCLEAN
cleanclean: fclean
	@rm -rf .vscode
	@echo "Cleancleaned."
