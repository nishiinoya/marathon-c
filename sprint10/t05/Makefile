NAME := parse_agents

all: $(NAME)

$(NAME):
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -o $(NAME) src/*.c

clean:
	rm -rf $(NAME)

uninstall:
	rm -rf $(NAME)

reinstall: uninstall $(NAME)
