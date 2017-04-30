#include <stdio.h>

int RegexFuncStart(int pos, char ch) {
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
    if (!_Regex(this, RegexFuncStart)) {
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
    if (!_Regex(this, RegexSpace)) {
        return 0;
    }
    if (!_Regex(this, RegexNotSpaceOrParenthesize)) {
        return 0;
    }
     if (this->ch != 40) {
        if (!_Regex(this, RegexStartParenthesize)) {
            return 0;
        }
    }
    
    if (!RegexFuncArgs(this)) {
        return 0;
    }

    if (!nextCharInline(this)) {
        return 0;
    }
   
    return RegexFuncInner(this);
}


int RegexFuncArgsType(struct sequenceRegex * this) {
    if (!_Regex(this, RegexStartParenthesize)) {
            return 0;
    }
    
    if (!RegexFuncTypeArgs(this)) {
        return 0;
    }

    if (!nextCharInline(this)) {
        return 0;
    }
   
    return RegexFuncInner(this);
}



