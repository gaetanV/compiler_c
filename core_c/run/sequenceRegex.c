#include <stdio.h>

struct sequenceRegex {
    int c;
    char ch;
    FILE *fp;
    char buff[255];
;
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

char currentChar(struct sequenceRegex * this) {  
    return this->ch;
}


int nextCharIs(struct sequenceRegex * this,char a) {
    printf("NextI | %c |  %d  \n", this->ch , this->ch);
    this->ch = fgetc(this->fp);
    if(this->ch == a){
        return 1;
    }
    return 0;
}

int nextCharInline(struct sequenceRegex * this) {
    printf("Next+ | %c |  %d  \n", this->ch , this->ch);
    this->ch = fgetc(this->fp);
    if(this->ch != EOF  ){
        return 1;
    }
    return 0;
};

int nextChar(struct sequenceRegex * this) {
    printf("Next- | %c |  %d  \n", this->ch , this->ch);
    this->ch = fgetc(this->fp);
    if(this->ch != EOF ){
        return 1;
    }
    return 0;
}
