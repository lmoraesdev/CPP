NAME = megaphone
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ./megaphone.cpp

OBJS =  $(SRC:%.cpp=%.o)

all:	${NAME}

${OBJS}:	${SRC}
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	@rm -rf ${OBJS}

fclean:		clean
	@rm -rf ${NAME}

re:			fclean all
