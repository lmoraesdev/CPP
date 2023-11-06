NAME = ScavTrap
CC = c++

CFLAGS = -std=c++98 -g -Wall -Werror -Wextra

SRC = ./main.cpp ClapTrap.cpp ScavTrap.cpp

OBJS =  $(SRC:%.cpp=%.o)

all:	${NAME}

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

${NAME}:	${OBJS}

	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	@rm -rf ${OBJS}

fclean:		clean
	@rm -rf ${NAME}

re:			fclean all
