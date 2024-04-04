flags := -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses
name := matrix_rain

all: PROJECT

PROJECT:
	@clang $(flags) src/*.c -o $(name)

clean:
	@rm -f $(name)

uninstall:
	@rm -f $(name)

reinstall:
	make uninstall
	make
