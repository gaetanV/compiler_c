#include <stdio.h>

int ClassJs(struct sequenceRegex * this) {

    if (!RegexExtendsImplements(this)) {
        return 0;
    }

    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 10:
                break;
            case 99:
                if (!RegexConstructor(this)) {
                    if (!RegexFuncNameArgs(this)) {
                        return 0;
                    }
                } else {
                    if (!RegexFuncArgsType(this)) {
                        return 0;
                    }
                }
                break;
            case 112:
                if (!nextCharInline(this)) {
                    return 0;
                }
                switch (this->ch) {
                    case 117:
                        if (!RegexUblic(this)) {
                            if (!RegexFuncNameArgs(this)) {
                                return 0;
                            }
                            printf("Module/End/Regex Func\n");  
                        } else {
                            printf("Module/End/Regex public\n");
                        }
                        break;
                    case 114:
                        if (!RegexRivate(this)) {
                            if (!RegexFuncNameArgs(this)) {
                                return 0;
                            }
                            printf("Module/End/Regex Func\n");  
                        } else {
                            printf("Module/End/Regex private\n");
                        }
                        break;
                    default:
                        if (!RegexFuncNameArgs(this)) {
                                return 0;
                        }
                        printf("Module/End/Regex Func\n");
                }
                break;
            case 115:
                if (!RegexStatic(this)) {
                    if (!RegexFuncNameArgs(this)) {
                        return 0;
                    }
                    printf("Module/End/Regex Func\n");
                } else {
                    if (!RegexFuncNameArgs(this)) {
                        return 0;
                    }
                    printf("Module/End/Regex static\n");
                }
                break;
            default:
                if (!RegexFuncNameArgs(this)) {
                     return 0;           
                } 
                printf("Module/End/Regex Func\n");
                break;
            case EOF:
                return 0;  
            case 125:
                return 1;  
                
        }
    }
    return 0;
}
