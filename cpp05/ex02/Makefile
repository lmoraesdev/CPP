NAME		= AForm

OBJ_PATH	=./obj/

CC			= c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g -Wshadow -Wno-shadow

VPATH	=	./

RM			= rm -rf

SRC 		= main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp

OBJ 		= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))

$(OBJ_PATH)%.o: %.cpp
			@printf "\n$(CY)Generating object...$(RC)\n"
			mkdir -p $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@
			@printf "\n$(GR)Object ready!$(RC)\n"

$(NAME): 	$(OBJ)
			@printf "\n$(CY)Generating executable...$(RC)\n"
			$(CC) $(CFLAGS) $(OBJ) -I $(OBJ_PATH) -o $(NAME)
			@printf "\n$(GR)Done!$(RC)\n"

all:		$(NAME)

re:			fclean all

run:		all
			./$(NAME)

clean:
			$(RM) $(OBJ) $(OBJ_PATH)
			$(RM) *_shrubbery
			@printf "\n$(RE)Objects removed!$(RC)\n\n"

fclean:		clean
			$(RM) $(NAME)
			@printf "\n$(RE)Executables removed!$(RC)\n\n"

leak:		all
			valgrind --leak-check=full --track-origins=yes ./${NAME}

# Colors
CY			= \033[36;1m
YE			= \033[33;1m
GR			= \033[32;1m
RE			= \033[31;1m
RC			= \033[0m
