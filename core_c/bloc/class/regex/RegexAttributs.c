#include <stdio.h>
/*
int RegexEndOfScriptLine(struct sequenceRegex * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 59:
                return 1;
        }

    }
}

int RegexEndOfScriptLineOrDouble(struct sequenceRegex * this) {   
      while (1) {
         switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 59:
                return 1;   
            case 58:
                return 2;  
        }
    } 
}

int RegexNotSpaceOrEndOfScriptLineOrDouble(struct sequenceRegex * this) {      
    while (1) {
         switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 32:
                return 1;  
            case 10:
                return 0;
            case 59:
                return 2;   
            case 58:
                return 3;  
        }
    }
}

int RegexAttributDouble(struct sequenceRegex * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 59:
                return 1;
            default:
                if (!RegexEndOfScriptLine(this)) {
                    return 0;
                }
                return 1;
        }
    }
    return 0;
}

int parseAttribut(struct sequenceRegex * this) {

    if (!RegexJumpSpace(this)) {
        return 0;
    }
    switch (RegexNotSpaceOrEndOfScriptLineOrDouble(this)) {
        case 0:
            return 0;
        case 1:
            switch (RegexEndOfScriptLineOrDouble(this)) {
                case 0:
                    return 0;
                case 2:
                    return RegexAttributDouble(this);
                case 1:
                    if (!RegexEndOfScriptLine(this)) {
                        return 0;
                    }
            }
            break;
        case 2:
            return 1;
        case 3:
            return RegexAttributDouble(this);
    }
    return 0;
}



int RegexAttributs(struct sequenceRegex * this, int(constructor) (struct sequenceRegex *)) {
    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 10:
                break;
            
            case 112:
             
                if (RegexP_(this, parseAttribut)) {
                    printf("Module/End/Regex p_\n");
                    printf("-----------------------------< \n");
                } else {
                    return 0;
                }
                break;
               break;
            case 40:
                // Parenthesize start
                return 1;

            default:
                break;
                return 0;
        }
    }
    return 0;
}

*/