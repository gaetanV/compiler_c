#include <stdio.h>

int ClassJsServer(struct sequenceRegex * this) {

    if (!RegexExtendsImplementsStartClass(this)) {
         printf("Error in class format extends implements \n");
        return 0;
    }

    return 0;
}
