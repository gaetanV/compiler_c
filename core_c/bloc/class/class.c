#include <stdio.h>
#include "./regex/RegexConstructor.c"
#include "./regex/RegexStatic.c"
#include "./regex/RegexP_.c"


#include "./collector/ClassCollectorFunc.c"
#include "./collector/ClassCollectorConstructor.c"
#include "./collector/ClassCollectorOption.c"

#include "./type/Unity/ClassCollectorUnity.c"
#include "./type/Unity/ClassUnityOutput.c"
#include "./type/Unity/ClassUnity.c"

#include "./type/JsServer/ClassCollectorJsServer.c"
#include "./type/JsServer/ClassJsServerOutput.c"
#include "./type/JsServer/ClassJsServer.c"

#include "./type/Js/ClassCollectorJs.c"
#include "./type/Js/ClassJs.c"
#include "./type/Js/ClassJsOutput.c"


void _RegexClassStart(struct Buffer * this){
    
   

    // REGEX Class FROM start at 99
    if (fgetc(this->fp) != 108) {
        goto errorFormat;
    }
    if (fgetc(this->fp) != 97) {

        goto errorFormat;
    }
    if (fgetc(this->fp) != 115) {

        goto errorFormat;
    }
    if (fgetc(this->fp) != 115) {
        goto errorFormat;
    }
    ///////////
    
    RegexJumpSpace(this);

    Memory(this);
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                goto errorFormat;
            case 10:
                goto errorFormat;
            case 59:
                goto errorFormat;
            case 123:
                Memory(this);
                return;
            case 32:
                 return;
            default:
                Memory(this);
                break;
        }
    }
    
errorFormat:
    Error(this, "class format");
    
}


int parseClassUnity(struct Buffer * this,   int(classOuputType) (struct Buffer *, struct ClassCollectorUnity * collector)) {
    _RegexClassStart(this);
    return ClassUnity(this,classOuputType); 
}


int parseClassJs(struct Buffer * this,   int(classOuputType) (struct Buffer *, struct ClassCollectorJs * collector)) {
    _RegexClassStart(this);
    return ClassJs(this,classOuputType); 
}


int parseClassJsServer(struct Buffer * this,   int(classOuputType) (struct Buffer *, struct ClassCollectorJsServer * collector)) {
    _RegexClassStart(this);
    return ClassJsServer(this,classOuputType);
}

