#include "run/Buffer.c"
#include "run/Error.c"
#include "run/Memory.c"

#include "run/Regexcommon.c"
#include "run/RegexFunc.c"

#include "bloc/header/header.c"
#include "bloc/class/class.c"


int scanJs(struct Buffer * this) {

    if (parseHeader(this)) {
        switch (this->ch) {
            case 99:
                if (parseClass(this, ClassUnity, ClassUnityOutput )) {
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
    fclose(this->fp);
 
    
    
    printf("All is done nice work");
    return 1;
}

int main(int argc, char *argv[]) {

    if (!argv[1]) {
        printf("File argument expected.\n");
        return 0;
    }

    struct Buffer seqRegex;

    SequenceInit(&seqRegex, argv[1]);
    return scanJs(&seqRegex);
  

}
