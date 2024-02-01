void mx_str_reverse(char *s){
    int last = 0;
    while(s[last] != '\0') {
        last++;
    }
    char temp = s[last];
    for (int i = 0; i < last / 2; i++) {
        char temp = s[i];
        s[i] = s[last - 1 - i];
        s[last - 1 - i] = temp;
    }
}

