NAME = fixed
CC = c++

CFLAGS = -std=c++98 -g

SRC = ./main.cpp ./Fixed.cpp

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
