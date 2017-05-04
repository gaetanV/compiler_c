#include <stdio.h>

int ClassJsServer(struct sequenceRegex * this) {

    if (!RegexExtendsImplementsStartClass(this)) {
         printf("Error in class format extends implements \n");
        return 0;
    }
    
    
    while (1) {
        switch (fgetc(this->fp)) {
            case 32:
                break;
            case 10:
                break;
            case 47:
                if(!RegexComments(this)){
                    return 0;
                }
                break;
            case 99:
                if (RegexConstructorOrFunc(this)) {
                    if (!RegexFuncArgsType(this)) {
                        return 0;
                    }
                    MemoryType(this,1);
                } else {
                    if (!RegexFuncNameArgs(this)) {
                        return 0;
                    }
                    MemoryType(this,0);
                }
                break;
            case 112:
                switch (fgetc(this->fp)) {
                    case EOF:
                        return 0;
                    case 10:
                        return 0;
                    case 59:
                        return 0;
                    case 117:
                        if (RegexUblicOrFunc(this)) {
                            if (!RegexJumpSpace(this)) {
                                return 0;
                            }
                            printf("Module/End/Regex public\n");
                            MemoryType(this,2);
                        } else {
                            printf("Module/End/Regex Func\n");
                            MemoryType(this,0);
                        }
                        if (!RegexFuncNameArgs(this)) {
                            return 0;
                        }
                        break;
                    case 114:
                        if (RegexRivateOrFunc(this)) {
                            if (!RegexJumpSpace(this)) {
                                return 0;
                            }
                            printf("Module/End/Regex private\n");
                            MemoryType(this,3);
                        } else {
                            printf("Module/End/Regex Func\n");
                            MemoryType(this,0);
                        }
                        if (!RegexFuncNameArgs(this)) {
                            return 0;
                        }
                        break;
                    default:
                        if (!RegexFuncNameArgs(this)) {
                            return 0;
                        }
                        MemoryType(this,0);
                        printf("Module/End/Regex Func\n");
                }
                break;
            case 115:
                if (RegexStaticOrFunc(this)) {
                    if (!RegexJumpSpace(this)) {
                        return 0;
                    }
                    printf("Module/End/Regex static\n");
                    MemoryType(this,2);                
                } else {
                    printf("Module/End/Regex Func\n");
                    MemoryType(this,0);
                }
                if (!RegexFuncNameArgs(this)) {
                    return 0;
                }
                break;
            default:
                MemoryClass(this);
                if (!RegexFuncNameArgs(this)) {
                    return 0;
                }
                MemoryType(this,555);
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
