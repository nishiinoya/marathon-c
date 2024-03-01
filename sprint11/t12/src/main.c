#include "../inc/list.h"

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 5) {
        mx_printerr("usage: ./playlist [file] [command] [args]\n");
        exit(0);
    }

    if (mx_strcmp(argv[2], "add") == 0 && argc == 5) {
        add_func(argv);

    } else if (mx_strcmp(argv[2], "print") == 0 && argc == 3) {
        print_func(argv);
    }

    else if (mx_strcmp(argv[2], "remove") == 0 && argc == 4) {
        remove_func(argv);

    } else if (mx_strcmp(argv[2], "sort") == 0 && argc == 4) {
    
        //sort

    } else {
        mx_printerr("ERROR\n");
        exit(0);
    }

    return 0;
}
