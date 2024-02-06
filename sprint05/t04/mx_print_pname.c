void mx_printchar(char c);
void mx_printstr(const char *s);
char *mx_strchr(const char *s, int c);
int mx_strlen(const char *s);

int main(int argc, char *argv[]) {
    char *name = argv[0];
    char *last_slash = mx_strchr(name, '/');

    while (last_slash) {
        name = last_slash + 1;
        last_slash = mx_strchr(name, '/');
    }

    mx_printstr(name);
    mx_printchar('\n');
    (void)argc;
    return 0;
}
