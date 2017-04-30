#include <stdio.h>

#include "./regex/RegexConstructor.c"
#include "./regex/RegexStatic.c"
#include "./regex/RegexP_.c"

int parseClass(struct sequenceRegex * this, int(constructor) (struct sequenceRegex *), int(function) (struct sequenceRegex *)) {

    // REGEX Class start at 99

    if (!nextCharIs(this, 108)) {
        return 0;
    }
    if (!nextCharIs(this, 97)) {
        return 0;
    }
    if (!nextCharIs(this, 115)) {
        return 0;
    }
    if (!nextCharIs(this, 115)) {
        return 0;
    }
    ///////////

    if (!nextCharInline(this)) {
        return 0;
    }
    if (!_Regex(this, RegexSpace)) {
        return 0;
    }

    if (!_Regex(this, RegexNotSpace)) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (!_Regex(this, RegexFuncStart)) {
        return 0;
    }
    while (nextChar(this)) {
        switch (this->ch) {
            case 99:
                printf(">----------------------------- \n");
                printf("Module/Find/Regex constructor\n");
                if (RegexConstructor(this, constructor)) {
                    printf("Module/End/Regex constructor\n");
                    printf("-----------------------------< \n");
                } else {
                    return 0;
                }
                break;
            case 112:
                printf(">----------------------------- \n");
                printf("Module/Find/Regex p_\n");
                if (RegexP_(this, function)) {
                    printf("Module/End/Regex p_\n");
                    printf("-----------------------------< \n");
                } else {
                    return 0;
                }
                break;
            case 115:
                printf(">----------------------------- \n");
                printf("Module/Find/Regex static \n");
                if (RegexStatic(this, function)) {
                    printf("Module/End/Regex static\n");
                    printf("-----------------------------< \n");
                } else {
                    return 0;
                }
                break;
            case 125:
                return 1;
            case 32:
                break;
            case 10:
                break;
            default:
                return 0;
                break;
        }
    }
    return 0;
}
