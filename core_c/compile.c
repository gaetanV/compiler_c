#include <stdio.h>

int parseFile(char *arg) {

    FILE *fp;
    char ch;

    fp = fopen (arg,"r");

    if (fp == NULL) {
        printf("File %s not found",arg);
        return 0; 
    } else  { 
        while((ch=fgetc(fp))!=EOF)
        {
          printf("%c",ch);
        }
    }

    fclose(fp);
    return 1; 
}

int main(int argc, char *argv[])
{
    if( argc != 2 ) {
       printf("File argument expected.\n");
       return 0; 
    }
    if(parseFile(argv[1])){
        printf("all is done nice work");
    } 
  
    return 0;  
}
