#include <stdio.h>
#include "./regex/RegexConstructor.c"
#include "./regex/RegexStatic.c"
#include "./regex/RegexP_.c"
#include "./regex/RegexAttributs.c"

#include "./type/ClassJsServer.c"
#include "./type/ClassJs.c"
#include "./type/ClassUnity.c"


int RegexClass( struct sequenceRegex * this){
    
    // REGEX Class start at 99
    if (fgetc(this->fp) != 108) {
        return 0;
    }
    if (fgetc(this->fp) != 97) {

        return 0;
    }
    if (fgetc(this->fp) != 115) {

        return 0;
    }
    if (fgetc(this->fp) != 115) {
        return 0;
    }
    ///////////

    if (!RegexJumpSpace(this)) {
        return 0;
    }

   
    if (!RegexMemoryNotSpaceInline(this)) {
        return 0;
    }
    
    MemoryExport(this,-2);
    MemoryMap(this);
    return 1;
}

int parseClass(
        struct sequenceRegex * this,
        int(classType) (struct sequenceRegex *)
) {
    
    if(!RegexClass(this)){
        printf("Error in class format \n");
        return 0;
    }
    return classType(this);
}

