# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#              #
#    Updated: 2024/09/03 16:45:48 by amaucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = form
SOURCES = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp \
		
OBJS = $(SOURCES:.cpp=.o)

CXX = c++
RM = rm -f
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98

all: $(NAME)	

$(NAME): $(OBJS)
	$(CXX) $(CXXLAGS) $(OBJS) -o $(NAME)

#rule for building .o files from .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re