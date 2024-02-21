NAME := read_file

all: $(NAME)

$(NAME):
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -o $(name) src/*.c

clean:
	rm -rf $(NAME)

uninstall:
	rm -rf $(NAME)

reinstall: uninstall $(NAME)
