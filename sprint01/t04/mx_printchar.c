#include <unistd.h>

void mx_printchar(char ch){
    write(1, &ch, 1);
}
