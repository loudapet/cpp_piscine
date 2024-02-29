# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouda <plouda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 10:28:25 by plouda            #+#    #+#              #
#    Updated: 2024/02/29 13:15:09 by plouda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	Account
SRCS =	Account.cpp tests.cpp

BUILD_DIR = ./obj
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS))
OBJS := $(OBJS:.cpp=.o)
HEADERS = -I Account.hpp
#SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))

COMP = c++ -g -Wall -Wextra -Werror -std=c++98

#HEADERS = -I ./include/

GREEN		=	$(shell printf "\033[1;32m")
YELLOW		=	$(shell printf "\033[1;33m")
CYAN		=	$(shell printf "\033[1;36m")
RESET		=	$(shell printf "\033[0m")

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Initiating compilation of '${NAME}'$(RESET)"
	@echo "$(YELLOW)Linking objects...$(RESET)"
	@$(COMP) $(OBJS) $(HEADERS) -o ${NAME}
	@echo "$(GREEN)Compilation of '${NAME}' successful.$(RESET)"

obj/%.o: %.cpp | objdir
	@$(COMP) -c $< -o $@

objdir:
	@mkdir -p obj

clean:
	@rm -rf ./obj
	@echo "$(YELLOW)Object files successfully removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Executable successfully removed.$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re, bonus