#include <stdio.h>



int newExport(struct sequenceRegex * this) {
    
    // REGEX EXPORT start at 101
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 120) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 112) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 111) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 114){
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 116) {
        return 0;
    }
    ///////////
    
   
    if (!nextCharInline(this)) {
        return 0;
    }

    if (!_Regex(this, RegexSpace)) {
        return 0;
    }

     
    // REGEX CLASS
    if (currentChar(this) != 99) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 108) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 97) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 115) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (currentChar(this) != 115) {
        return 0;
    }
    ///////////
  
    
    if (!nextCharInline(this)) {
        return 0;
    }
    if (!_Regex(this, RegexSpace)) {
        return 0;
    }

    if (!_Regex(this, RegexNotSpace)) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    if (!_Regex(this, RegexStartFunc)) {
        return 0;
    }
    printf("seq export complete \n");
    return 1;
}
