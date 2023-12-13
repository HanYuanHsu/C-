#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <error.h>

void diamond(char *str) {
    int length = strlen(str);
    char cpy[length+1];
    for (int i=0; i < length; i++) {
        strncpy(cpy, str, i+1);
        cpy[i+1] = '\0';
        printf();
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        error(1, 0, "Sorry! Input an argument next time!");
    }
    char *arg = argv[1];
    diamond(arg);
}
