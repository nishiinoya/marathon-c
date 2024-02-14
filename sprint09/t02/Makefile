CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
LIBNAME = minilibmx.a

SRC_FILES = \
    $(SRC_DIR)/mx_atoi.c \
    $(SRC_DIR)/mx_isdigit.c \
    $(SRC_DIR)/mx_isspace.c \
    $(SRC_DIR)/mx_printchar.c \
    $(SRC_DIR)/mx_printint.c \
    $(SRC_DIR)/mx_printstr.c \
    $(SRC_DIR)/mx_strcpy.c \
    $(SRC_DIR)/mx_strcmp.c \
    $(SRC_DIR)/mx_strlen.c

OBJ_FILES = \
    $(OBJ_DIR)/mx_atoi.o \
    $(OBJ_DIR)/mx_isdigit.o \
    $(OBJ_DIR)/mx_isspace.o \
    $(OBJ_DIR)/mx_printchar.o \
    $(OBJ_DIR)/mx_printint.o \
    $(OBJ_DIR)/mx_printstr.o \
    $(OBJ_DIR)/mx_strcpy.o \
    $(OBJ_DIR)/mx_strcmp.o \
    $(OBJ_DIR)/mx_strlen.o


all: 
	make MINILIBMX

MINILIBMX: $(OBJ_FILES)
	ar rcs $(LIBNAME) $(OBJ_FILES)

$(OBJ_DIR)/mx_atoi.o: $(SRC_DIR)/mx_atoi.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mx_atoi.c -o $(OBJ_DIR)/mx_atoi.o

$(OBJ_DIR)/mx_isdigit.o: $(SRC_DIR)/mx_isdigit.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mx_isdigit.c -o $(OBJ_DIR)/mx_isdigit.o

$(OBJ_DIR)/mx_isspace.o: $(SRC_DIR)/mx_isspace.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mx_isspace.c -o $(OBJ_DIR)/mx_isspace.o

$(OBJ_DIR)/mx_printchar.o: $(SRC_DIR)/mx_printchar.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mx_printchar.c -o $(OBJ_DIR)/mx_printchar.o

$(OBJ_DIR)/mx_printint.o: $(SRC_DIR)/mx_printint.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mx_printint.c -o $(OBJ_DIR)/mx_printint.o

$(OBJ_DIR)/mx_printstr.o: $(SRC_DIR)/mx_printstr.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mx_printstr.c -o $(OBJ_DIR)/mx_printstr.o

$(OBJ_DIR)/mx_strcpy.o: $(SRC_DIR)/mx_strcpy.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mx_strcpy.c -o $(OBJ_DIR)/mx_strcpy.o

$(OBJ_DIR)/mx_strcmp.o: $(SRC_DIR)/mx_strcmp.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mx_strcmp.c -o $(OBJ_DIR)/mx_strcmp.o

$(OBJ_DIR)/mx_strlen.o: $(SRC_DIR)/mx_strlen.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mx_strlen.c -o $(OBJ_DIR)/mx_strlen.o

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

uninstall: clean
	rm -f $(LIBNAME)

reinstall: uninstall all
