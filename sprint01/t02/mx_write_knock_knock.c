#include <unistd.h>
#include <string.h>

void mx_write_knock_knock(void) {
    const char *message = "Follow the white rabbit.\nKnock, knock, Neo.\n";
    write(1, message, strlen(message));
}
