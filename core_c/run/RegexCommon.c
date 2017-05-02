

int RegexJumpSpace(struct sequenceRegex * this) {
    while (1) {
        if (!nextCharIs(this, 32)) {
            return 1;
        }
    };
}

int RegexNotSpaceInline(struct sequenceRegex * this) {
    while (1) {
         this->ch = fgetc(this->fp);
         switch (this->ch) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 59:
                return 0;   
            case 32:
                return 1;      
        }
    }
}

int RegexEndOfScriptLine(struct sequenceRegex * this) {
    while (1) {
         switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 59:
                return 1;   
        }
    }
}


int RegexEndOfScriptLineOrDouble(struct sequenceRegex * this) {   
      while (1) {
         switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 59:
                return 1;   
            case 58:
                return 2;  
        }
    }
    
    
}



int RegexNotSpaceOrEndOfScriptLineOrDouble(struct sequenceRegex * this) {      
    while (1) {
         switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 32:
                return 1;  
            case 10:
                return 0;
            case 59:
                return 2;   
            case 58:
                return 3;  
        }
    }
}


int RegexNotSpaceOrEndOfScriptLine(struct sequenceRegex * this) {
    while (1) {
         switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;  
            case 32:
                return 1;  
            case 59:
                return 2;   
        }
    }
}

int RegexNotSpaceOrParenthesize(struct sequenceRegex * this) {
     while (1) {
         switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 10:
                return 0;
            case 32:
                return 1;  
            case 40:
                return 2; 
        }
    }
}

int RegexStartParenthesize(struct sequenceRegex * this) {
    while (1) {
        switch (fgetc(this->fp)) {
            default:
                return 0;
            case 32:
                break;
            case 40:
                return 1;   
        }
    }
}



