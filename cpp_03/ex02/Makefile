# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouda <plouda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 10:28:25 by plouda            #+#    #+#              #
#    Updated: 2024/03/18 10:02:00 by plouda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	FragTrap
SRCS =	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
		

#SRCS_DIR = ./src
BUILD_DIR = ./obj
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS))
OBJS := $(OBJS:.cpp=.o)
#SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
HEADERS = -I ClapTrap.hpp -I ScavTrap.hpp -I FragTrap.hpp

COMP = c++ -g -Wall -Wextra -Werror -std=c++98


GREEN		=	$(shell printf "\033[1;32m")
YELLOW		=	$(shell printf "\033[1;33m")
CYAN		=	$(shell printf "\033[1;36m")
RESET		=	$(shell printf "\033[0m")

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Initiating compilation of '${NAME}'$(RESET)"
	@echo "$(YELLOW)Linking objects...$(RESET)"
	@$(COMP) $(OBJS) -o ${NAME}
	@echo "$(GREEN)Compilation of '${NAME}' successful.$(RESET)"

obj/%.o: %.cpp | objdir
	@$(COMP) -c $< -o $@ $(HEADERS)

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