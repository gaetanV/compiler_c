#include <stdio.h>
#include "./regex/RegexConstructor.c"
#include "./regex/RegexStatic.c"
#include "./regex/RegexP_.c"

#include "./collector/ClassCollector.c"
#include "./collector/ClassCollectorFunc.c"
#include "./collector/ClassCollectorConstructor.c"
#include "./collector/ClassCollectorOption.c"

#include "./type/Js/ClassJs.c"
#include "./type/Js/ClassJsOutput.c"
#include "./type/JsServer/ClassJsServerOutput.c"
#include "./type/Unity/ClassUnityOutput.c"


#include "./type/JsServer/ClassJsServer.c"
#include "./type/Unity/ClassUnity.c"

int parseClass(
        struct Buffer * this,
        int(classType) (struct Buffer *, struct ClassCollector * collector),
        int(classOuputType) (struct Buffer *, struct ClassCollector * collector)
        ) {

    struct ClassCollector classCollector;

    // Module Memory Position
    ClassCollectorInit(&classCollector, this->_pointer - 1);

 
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
                goto endClass;
            case 32:
                goto endClass;
            default:
                Memory(this);
                break;
        }
    }

endClass:
    if (classType(this, &classCollector)) {
        classOuputType(this, &classCollector);
        return 1;
    }
    return 0;


errorFormat:
    Error(this, "class format");

}

