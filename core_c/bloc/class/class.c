#include <stdio.h>
#include "./regex/RegexConstructor.c"
#include "./regex/RegexStatic.c"
#include "./regex/RegexP_.c"
#include "./regex/RegexAttributs.c"
#include "./regex/RegexFuncExtends.c"

#include "./ClassCollector.c"
#include "./ClassCollectorCommon.c"

#include "./type/Js/ClassJs.c"
#include "./type/Js/ClassJsOutput.c"
#include "./type/JsServer/ClassJsServerOutput.c"

#include "./type/JsServer/ClassJsServer.c"
#include "./type/Unity/ClassUnity.c"


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
    

 
    return 1;
}

int parseClass(
        struct sequenceRegex * this,
        int(classType) (struct sequenceRegex *, struct ClassCollector * collector),
        int(classOuputType) (struct sequenceRegex *, struct ClassCollector * collector)
) {

    
    struct ClassCollector classCollector;
   
    
    // Module Memory Position
    ClassCollectorInit(&classCollector,this->_pointer - 1) ;
    
    
    if(!RegexClass(this)){
        printf("Error in class format \n");
        return 0;
    }
    if(classType(this,&classCollector)){
        classOuputType(this,&classCollector);
        return 1;
        
    }
    return 0;
 
 
}

