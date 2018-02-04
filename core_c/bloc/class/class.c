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

/**
   @ERROR
 */
void ErrorClass(struct Buffer * buffer) {
    Error(buffer, "Class format");
}

/**
@TOOLS
 */
// REGEX Class FROM start at 99
#define _RegexFrom(buffer)\
    if (fgetc(buffer->fp) != 108) { ErrorClass(buffer); }\
    if (fgetc(buffer->fp) != 97)  { ErrorClass(buffer); }\
    if (fgetc(buffer->fp) != 115) { ErrorClass(buffer); }\
    if (fgetc(buffer->fp) != 115) { ErrorClass(buffer); }\
    RegexJumpSpace(buffer);\
    Memory(buffer);\


void _RegexClassStart(struct Buffer * buffer) {
    _RegexFrom(buffer);
    while (1) {
        switch (buffer->ch = fgetc(buffer->fp)) {
            case EOF:
                ErrorClass(buffer);
            case 10:
                ErrorClass(buffer);
            case 59:
                ErrorClass(buffer);
            case 32:
                MemoryMap(buffer);
                return;
            case 123:
                MemoryMap(buffer);
                Memory(buffer);
                return;
            default:
                Memory(buffer);
                break;
        }
    }
}

/**
@@@@@@@
 */
int parseClassUnity(struct Buffer * buffer, int(classOuputType) (struct Buffer *, struct ClassCollectorUnity * collector)) {
    _RegexClassStart(buffer);
    return ClassUnity(buffer, classOuputType);
}

int parseClassJs(struct Buffer * buffer, int(classOuputType) (struct Buffer *, struct ClassCollectorJs * collector)) {
    _RegexClassStart(buffer);
    return ClassJs(buffer, classOuputType);
}

int parseClassJsServer(struct Buffer * buffer, int(classOuputType) (struct Buffer *, struct ClassCollectorJsServer * collector)) {
    _RegexClassStart(buffer);
    return ClassJsServer(buffer, classOuputType);
}