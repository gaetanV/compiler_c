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
                if (RegexConstructorOrFunc(this)) {
                    if (!RegexFuncArgsType(this)) {
                        return 0;
                    }
                } else {
                    if (!RegexFuncNameArgs(this)) {
                        return 0;
                    }
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
                        } else {
                            printf("Module/End/Regex Func\n");
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
