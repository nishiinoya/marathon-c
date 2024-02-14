CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC_DIR = src
OBJ_DIR = obj
LIBNAME = minilibmx.a

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: MINILIBMX

MINILIBMX: $(LIBNAME)

$(LIBNAME): $(OBJ_FILES)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

uninstall: 
	rm -f $(LIBNAME)

reinstall: uninstall all


