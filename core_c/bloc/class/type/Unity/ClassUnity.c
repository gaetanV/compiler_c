#include <stdio.h>

int ClassUnity(struct sequenceRegex * this) {

    if (!RegexExtendsImplementsStartClass(this)) {
        return 0;
    }

    switch (RegexAttributs(this, RegexFuncArgsType)) {
        case 0:
            return 0;
    }
    

    

    return 1;
}
