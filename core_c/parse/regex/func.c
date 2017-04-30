#include <stdio.h>

int newFuncArgs(struct sequenceRegex * this) {

    if (currentChar(this) != 40) {
        if (!_Regex(this, RegexStartParenthesize)) {
            return 0;
        }
    }
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
                if(this->c = 2){
                     printf("End Type \n");
                     this->c = 3;
                }
                break;
            default:
                if(this->c == 1){
                     printf("Start Type \n");
                     this->c = 2;
                }
                if(this->c == 3){

                     printf("Start Param \n");
                     this->c = 4;
                }
                break;
        }
        printf(">> %c \n",this->ch);
      
        
    } while (this->ch != 41);
   


    if (!nextCharInline(this)) {
        return 0;
    }
    if (!_Regex(this, RegexStartFunc)) {
        return 0;
    }

    this->c = 1;
    do {
        if (!nextChar(this)) {
            return 0;
        }
        switch (currentChar(this)) {
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

int newFuncNameArgs(struct sequenceRegex * this) {
    if (!_Regex(this, RegexSpace)) {
        return 0;
    }
    if (!_Regex(this, RegexNotSpaceOrParenthesize)) {
        return 0;
    }
    return newFuncArgs(this);

}


