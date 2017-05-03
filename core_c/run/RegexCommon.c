int RegexEmptyLigne(struct sequenceRegex * this) {
    while(1){
        switch (this->ch = fgetc(this->fp)){           
            case 32:
                break;
            case 10:
                return 1;
            default:
                return 0;
        }
    }
}

int RegexJumpSpace(struct sequenceRegex * this) {
    while (1) {
        if (!nextCharIs(this, 32)) {
            return 1;
        }
    };
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

