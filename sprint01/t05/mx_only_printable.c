void mx_printchar(char c);

void mx_only_printable(void){
    for (char ch = 126; ch >= 32; --ch){
        mx_printchar(ch);
    }
    mx_printchar('\n');
}
