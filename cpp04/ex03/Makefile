NAME = AMateria
CC = c++

CFLAGS = -std=c++98 -g #-Wall -Werror -Wextra

SRC =  ./AMateria.cpp ./Cure.cpp ./Ice.cpp ./ICharacter.cpp ./Character.cpp ./IMateriaSource.cpp ./MateriaSource.cpp ./main.cpp


OBJS =  $(SRC:%.cpp=%.o)

all:	${NAME}

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

${NAME}:	${OBJS}

	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	@rm -rf ${OBJS}

fclean:		clean
	@rm -rf ${NAME}

re:			fclean all
