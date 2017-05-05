#include "run/sequenceRegex.c"
#include "run/Regexcommon.c"
#include "run/RegexMemory.c"
#include "run/RegexFunc.c"
#include "run/RegexFuncExtends.c"
#include "bloc/header/header.c"
#include "bloc/class/class.c"


int scanJs(struct sequenceRegex * this) {
    if (parseHeader(this)) {
        switch (this->ch) {
            case 99:
                
                if (parseClass(this, ClassJs)) {
                    printf("Module done.\n");
                } else {
                    printf("Error in Module");
                    return 0;
                }
                break;
            default:
                printf("Only export class.\n");
                return 0;
        }
    } else {
        printf("Error in header");
        return 0;
    }
    SequenceFlush(this);
    OutputClassJsEcma6(this);
    
    
    printf("All is done nice work");
    return 1;
}

int main(int argc, char *argv[]) {

    if (!argv[1]) {
        printf("File argument expected.\n");
        return 0;
    }

    struct sequenceRegex seqRegex;
    
    if (!SequenceInit(&seqRegex, argv[1])) { 
        return 0;
    }
    
    return scanJs(&seqRegex);
  

}
