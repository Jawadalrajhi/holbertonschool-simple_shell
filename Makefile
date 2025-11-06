# Compiler
CC = gcc

# Compilation flags
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Target executable name
NAME = hsh

# Source files
SRC = main.c prompt.c exec.c path.c builtins.c utils.c

# Object files (generated automatically)
OBJ = $(SRC:.c=.o)

# Default target: build the program
all: $(NAME)

# Link object files into the final executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Remove object files
clean:
	rm -f $(OBJ)

# Remove object files and executable
fclean: clean
	rm -f $(NAME)

# Recompile everything from scratch
re: fclean all

# Run the shell for testing
run: all
	./$(NAME)
