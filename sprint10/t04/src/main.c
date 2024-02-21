#include "../inc/header.h"


void print_counts(int lin_count, int words_count, int bytes_count, char *file_name) {
    mx_printchar('\t');
    mx_printint(lin_count);
    mx_printchar('\t');
    mx_printint(words_count);
    mx_printchar('\t');
    mx_printint(bytes_count);

    if (file_name) {
        mx_printchar(' ');
        mx_printstr(file_name);
    }

    mx_printchar('\n');
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        char *str = mx_strnew(1);
        char *c = mx_strnew(1);
        int lin_count = 0, words_count = 0, bytes_count = 0;

        while (read(0, c, 1)) {
            if (*c == '\n')
                lin_count++;

            char *temp = str;
            str = mx_strjoin(str, c);
            free(temp);

            bytes_count++;
        }

        words_count = mx_count_words(str); 

        print_counts(lin_count, words_count, bytes_count, NULL);

        exit(1);
    }

    int total_words_count = 0, total_l = 0, total_bytes_count = 0;
    for (int i = 1; i < argc; i++) {
        int src = open(argv[i], O_RDONLY);
        struct stat st;
        if (src == -1) {
            mx_printerr("mx_wc: ");
            mx_printerr(argv[i]);
            mx_printerr(": ");
            switch (errno) {
            case EISDIR:
                mx_printerr("read: ");
                break;
            case ENOENT:
                mx_printerr("open: ");
                break;
            default:
                mx_printerr("unknown error: ");
            }
            mx_printerr(strerror(errno));
            mx_printerr("\n");

            exit(-1);

        } else if (fstat(src, &st) == 0 && S_ISDIR(st.st_mode)) {
            close(src);
            mx_printerr("mx_wc: ");
            mx_printerr(argv[i]);
            mx_printerr(": read: ");
            mx_printerr("Is a directory\n");
            continue;
        } else {
            char *str = mx_strnew(1);
            char *c = mx_strnew(1);
            int lin_count = 0;
            int words_count = 0;
            int bytes_count = 0;

            while (read(src, c, 1)) {
                if (*c == '\n')
                    lin_count++;

                char *temp = str;
                str = mx_strjoin(str, c);
                free(temp);

                bytes_count++;
            }

            if (read(src, c, 1) == -1) {
                mx_printerr("mx_wc: ");
                mx_printerr(argv[i]);
                mx_printerr(": read: ");
                mx_printerr(strerror(errno));
                mx_printerr("\n");

                exit(-1);
            }

            words_count = mx_count_words(str);

            total_words_count += words_count;
            total_l += lin_count;
            total_bytes_count += bytes_count;

            print_counts(lin_count, words_count, bytes_count, argv[i]);

            close(src);
        }
    }

    if (total_bytes_count && argc > 2)
        print_counts(total_l, total_words_count, total_bytes_count, "total");

    return 0;
}
