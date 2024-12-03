NAME:= MutantStack
CC:= c++
FLAGS:= -Wall -Wextra -Werror -std=c++11 #-g -fsanitize=address
OBJDIR := objects
TPP_FILES := MutantStack.tpp # new for the tpp
HEADER_FILES := MutantStack.hpp
SRC_FILES := main.cpp
SRC := $(addprefix src/, $(SRC_FILES))
HEADER := $(addprefix inc/, $(HEADER_FILES) $(TPP_FILES))
OBJS := $(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@printf "\033[1;34m---------\\n MAKE $(NAME) \n---------\\n\033[0m"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(OBJDIR)/%.o : %.cpp $(HEADER)
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

run: $(NAME)
	@printf "\033[1;33m---------\\n RUN $(NAME) \n---------\\n\033[0m"
	@./$(NAME)

clean:
	@if [ -d "$(OBJDIR)" ]; then \
		printf "\033[1;34m--------------\n removing OBJ files \n--------------\n\033[0m"; \
		$(RM) -r $(OBJDIR); \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		printf "\033[1;34m--------------\n removing $(NAME) \n--------------\n\033[0m"; \
		$(RM) $(NAME); \
	fi


re: fclean all

.PHONY: clean fclean re run all