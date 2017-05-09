#include <stdio.h>

#include "./regex/RegexImport.c"
#include "./regex/RegexExport.c"

int parseHeader(struct Buffer * this) {
    this->import = 0;
    MemoryMap(this);
    while (1) {
        switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 105:
                RegexStrictImport(this);
                this->import++;
                break;
            case 101:
                RegexStrictExport(this);
                return 1;
            case 47:
                RegexStrictComments(this);
                break;
            case 32:
                break;
            case 10:
                break;
            default:
                return 0;
                break;
        }
    }
    return 1;
}