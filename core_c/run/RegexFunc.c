#include <stdio.h>

int RegexFuncStart(struct sequenceRegex * this) {
      while (1) {
         switch (fgetc(this->fp)) {
            case 32:
                break; 
            case 23:
                break;   
            case 123:
                return 1;  
            default:
                return 0;
        }
    }
}

int RegexNotSpaceInlineOrFuncStart(struct sequenceRegex * this) {
    while (1) {
         switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 59:
                return 0;   
            case 32:
                return 1; 
            case 123:
                return 2;
        }
    }
}



int RegexFuncArgs(struct sequenceRegex * this) {
    this->c = 1;
    do {
        if (!nextCharInline(this)) {
            return 0;
        }
        switch (this->ch) {
            case 41:
                printf("End param \n");
                break;
            case 44:
                printf("End param \n");
                this->c = 1;
                break;
            case 32:
                break;  
            default:
                if( this->c == 1){
                    printf("Start param \n");
                }
                this->c = 2;
                break;
             
        }
      
    } while (this->ch != 41);
    
}

int RegexFuncTypeArgs(struct sequenceRegex * this) {
    this->c = 1;
    do {
        if (!nextCharInline(this)) {
            return 0;
        }
        switch (this->ch) {
            case 41:
                printf("End param \n");
                break;
            case 44:
                printf("End param \n");
                this->c = 1;
                break;
            case 32:
                if (this->c = 2) {
                    printf("End Type \n");
                    this->c = 3;
                }
                break;
            default:
                if (this->c == 1) {
                    printf("Start Type \n");
                    this->c = 2;
                }
                if (this->c == 3) {
                    printf("Start Param \n");
                    this->c = 4;
                }
                break;
        }
    } while (this->ch != 41);
}

int RegexFuncInner(struct sequenceRegex * this) {

    if (!RegexFuncStart(this)) {
        return 0;
    }

    this->c = 1;
    do {
        if (!nextChar(this)) {
            return 0;
        }
        switch (this->ch) {
            case 123:
                this->c++;
                break;
            case 125:
                this->c--;
                break;
        }
    } while (this->c != 0);
    return 1;
}
    

int RegexFuncNameArgs(struct sequenceRegex * this) {
    if (!RegexJumpSpace(this)) {
        return 0;
    }
    
    switch(RegexNotSpaceOrParenthesize(this)){
        case 0:
            return 0;
            break;
        case 1:
            if (!RegexStartParenthesize(this)) {
                return 0;
            }
            break;  
    }

    if (!RegexFuncArgs(this)) {
        return 0;
    }

    return RegexFuncInner(this);
}


int RegexFuncArgsType(struct sequenceRegex * this) {
    if (!RegexStartParenthesize(this)) {
            return 0;
    }
    
    if (!RegexFuncTypeArgs(this)) {
        return 0;
    }
   
    return RegexFuncInner(this);
}


