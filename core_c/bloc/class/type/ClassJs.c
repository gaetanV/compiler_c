#include <stdio.h>

int ClassJs(struct sequenceRegex * this) {

    if (!RegexExtendsStartClass(this)) {
        printf("Error in class format extends \n");
        return 0;
    }

    MemoryMap(this);
    
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
          
                    if (!RegexFuncArgs(this)) {
                        return 0;
                    }
                } else {
                    if (!RegexFuncNameArgs(this)) {
                        return 0;
                    }
                }
                break;
            case 115:
                if (RegexStaticOrFunc(this)) {
                    if (!RegexJumpSpace(this)) {
                        return 0;
                    }
                    printf("Module/End/Regex static\n");
                } else {
                    printf("Module/End/Regex Func\n");
                }
                if (!RegexFuncNameArgs(this)) {
                    return 0;
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
