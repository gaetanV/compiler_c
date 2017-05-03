#include <stdio.h>
#include "./regex/RegexConstructor.c"
#include "./regex/RegexStatic.c"
#include "./regex/RegexP_.c"
#include "./regex/RegexAttributs.c"


#include "./type/ClassJs.c"
#include "./type/ClassUnity.c"

int parseClass(
    struct sequenceRegex * this,
    int(classType) (struct sequenceRegex *)
){
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

    if (!RegexJumpSpace(this)) {
        return 0;
    }
    
 
    if (!RegexMemoryNotSpaceInline(this)) {
        return 0;
    }
   
    return classType(this);
}

