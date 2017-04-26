#include <stdio.h>
#include "parse/header.c"

int parseFile(char *arg) {

    char ch;
    FILE *fp;

    fp = fopen(arg, "r");

    if (fp == NULL) {
        printf("File %s not found", arg);
        return 0;
    } else {
        
        if(parseHeader(fp)){
            while ((ch = fgetc(fp)) != EOF ) {
                printf("-- %c\n", ch);
            }
            
        }else{
            return 0;
        }
     
    }
    fclose(fp);
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("File argument expected.\n");
        return 0;
    }
    if (parseFile(argv[1])) {
        printf("all is done nice work");
    }
    return 0;
}
