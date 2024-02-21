CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic
EXECUTABLE := playlist

all: $(EXECUTABLE)

$(EXECUTABLE):
	clang $(CFLAGS) src/*.c -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

uninstall:
	rm -f $(EXECUTABLE)

reinstall:
	make uninstall
	make