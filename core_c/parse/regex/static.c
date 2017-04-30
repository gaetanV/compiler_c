#include <stdio.h>


int newStatic(struct sequenceRegex * this) {
  
     
    // REGEX STATIC Start at 115
    if (!nextCharInline(this)) {
        return 0;
    }
       
    if (currentChar(this) != 116) {
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
   
    if (currentChar(this) != 116) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    
    if (currentChar(this) != 105) {
        return 0;
    }
     
    if (!nextCharInline(this)) {
        return 0;
    }
  
    if (currentChar(this) != 99) {
        return 0;
    }
    if (!nextCharInline(this)) {
        return 0;
    }
    ///////////
        
    
    if (!nextCharInline(this)) {
        return 0;
    }
    return newFuncNameArgs(this);
}
