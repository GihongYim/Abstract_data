NAME		=	abstract_data
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -Iinclude
STD98		=	-std=c++98

SRCS =	main.cpp \

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(STD98) -c $< -o $@ 

$(NAME) : $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(STD98) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	make clean
	rm -rf $(NAME)
re 	:
	make fclean
	make all

.PYONY : all re clean fclean

