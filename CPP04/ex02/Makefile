CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
# CXXFLAGS += -g -fsanitize=address
NAME = ex
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

OBJS = ${SRCS:.cpp=.o}

all:	$(NAME)

$(NAME):	${OBJS}
		$(CXX) $(CXXFLAGS) -o $(NAME) ${OBJS}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	rm -rf ${OBJS}
fclean: clean
	rm -rf ${NAME}

re: fclean all
