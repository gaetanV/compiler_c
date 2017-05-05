#include <stdio.h>

#include "./regex/RegexImport.c"
#include "./regex/RegexExport.c"

int parseHeader(struct sequenceRegex * this) {
  
  
    this->import[0] = this->_pointer;
    this->import[1] = 0;
 
   
    MemoryMap(this);
    while (1) {
        switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 105:
                if (!RegexImport(this)) {
                    printf("Error in import format \n");
                    return 0;
                } else {
                   this->import[1]++;
                }
                break;
            case 101:
                if (!RegexExport(this)) {
                    printf("Error in export format \n");
                    return 0;
                } else {
                    return 1;
                }
                break;
            case 47:
                if (!RegexComments(this)) {
                    return 0;
                }
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