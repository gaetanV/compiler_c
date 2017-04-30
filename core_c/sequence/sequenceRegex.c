#include <stdio.h>

struct sequenceRegex {
    int c;
    char ch;
    FILE *fp;
};

int SequenceInit(struct sequenceRegex * this, char *  c) {
    this->fp = fopen(c, "r");
    if (this->fp  == NULL) {
        printf("File %s not found", c);
        return 0;
    } 
    this->c = 0;
    return 1;
};


void SequenceFlush(struct sequenceRegex * this){
        fclose(this->fp);
}

int SequenceEmptyLigne(struct sequenceRegex * this) {
    do {
        this->ch = fgetc(this->fp);   
    }while (this->ch != EOF && this->ch != 10 && this->ch == 32);
    return 1;
}

int nextCharIs(struct sequenceRegex * this,char a) {
    printf("NextI | %c |  %d  \n", this->ch , this->ch);
    this->ch = fgetc(this->fp);
    if(this->ch == a){
        return 1;
    }
    return 0;
}
char currentChar(struct sequenceRegex * this) {  
    return this->ch;
}


char nextCharInline(struct sequenceRegex * this) {
    printf("Next+ | %c |  %d  \n", this->ch , this->ch);
    this->ch = fgetc(this->fp);
    if(this->ch != EOF && this->ch != 10){
        return this->ch;
    }
    return 0;
};

char nextChar(struct sequenceRegex * this) {
    printf("Next- | %c |  %d  \n", this->ch , this->ch);
    this->ch = fgetc(this->fp);
    if(this->ch != EOF ){
        return this->ch;
    }
    return 0;
}

char _Regex(struct sequenceRegex * this, int(f) (int, char)) {
    this->c = 0;
    do {
        printf("Regex | %c |  %d  \n", this->ch , this->ch);
  
        switch (f(this->c, this->ch)) {
            case 0:
                return 0;
                break;
            case 2:
                return this->ch;
                break;
        }
        this->c++;
    } while ((this->ch = fgetc(this->fp)) != EOF);
    return 0;
}
