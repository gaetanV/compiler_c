#include <stdio.h>

struct sequenceRegex {
    int c;
    char ch;
    FILE *fp;
};

void initSequenceRegex(struct sequenceRegex * this, FILE * fp) {
    this->fp = fp;
    this->c = 0;
  
};

char currentChar(struct sequenceRegex * this) {
    return this->ch;
};

char nextCharInline(struct sequenceRegex * this) {
    this->ch = fgetc(this->fp);
    if(this->ch != EOF && this->ch != 10){
        return this->ch;
    }
    return 0;
};

char nextChar(struct sequenceRegex * this) {
    this->ch = fgetc(this->fp);
    if(this->ch != EOF ){
        return this->ch;
    }
    return 0;
}

char _Regex(struct sequenceRegex * this, int(f) (int, char)) {
    this->c = 0;
    do {
        printf(" %d \n", this->ch);
        printf(" %c \n", this->ch);

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

int emptyLigne(struct sequenceRegex * this) {
    do {
        this->ch = fgetc(this->fp);
        printf("O %c\n", this->ch);
        
    }    while (this->ch != EOF && this->ch != 10);
    return 1;
}



int RegexSpace(int pos, char ch) {
    switch (ch) {
        case 32:
            return 3;
        case 10:
            return 0;
        default:
            return 2;
    }
}


int RegexNotSpace(int pos, char ch) {
    switch (ch) {
        case 32:
            return 2;
        case 10:
            return 0;
        default:
            return 3;
    }
}

int RegexStartFunc(int pos, char ch) {
    switch (ch) {
        case 123:
            return 2;
        case 32:
            return 3; 
        case 23:
            return 3;
        default:
            return 0;
    }
}

int RegexEndFunc(int pos, char ch) {
    switch (ch) {
        case 125:
            return 2;
        default:
            return 1;
    }
}



int RegexEndOfLine(int pos, char ch) {
    switch (ch) {
        case 59:
            return 2;
        case 32:
            return 1;
        default:
            return 0;
    }
}

int RegexNotSpaceOrEndOfLine(int pos, char ch) {
    switch (ch) {
        case 59:
            return 2;
        case 32:
            return 2;
        case 10:
            return 0;
        default:
            return 3;
    }
}

int RegexNotSpaceOrParenthesize(int pos, char ch) {
     switch (ch) {
        case 40:
            return 2;
        case 32:
            return 2;
        case 10:
            return 0;
        default:
            return 3;
    }
}

int RegexStartParenthesize(int pos, char ch) {
    switch (ch) {
        case 40:
            return 2;
        case 32:
            return 1;
        case 23:
            return 0;
        default:
            return 3;
    }
}

int RegexEndParenthesize(int pos, char ch){
     switch (ch) {
        case 41:
            return 2;
        case 32:
            return 1;
        case 23:
            return 0;
        default:
            return 3;
    }
}