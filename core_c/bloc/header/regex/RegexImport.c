void RegexStrictImport(struct Buffer * this) {

    // REGEX IMPORT Start at 105
    if (fgetc(this->fp) != 109) {
        goto importError;
    }
    if (fgetc(this->fp) != 112) {
        goto importError;
    }
    if (fgetc(this->fp) != 111) {
        goto importError;
    }
    if (fgetc(this->fp) != 114) {
        goto importError;
    }
    if (fgetc(this->fp) != 116) {
        goto importError;
    }

    RegexStrictSpaces(this);

    // REGEX NotSpaceInline
    Memory(this);
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                goto importError;
            case 10:
                goto importError;
            case 59:
                goto importError;
            case 32:
                goto step2;
            default:
                Memory(this);
                break;
        }
    }
    
step2:
                
    MemoryMap(this);

    RegexJumpSpace(this);
    
    // REGEX FROM

    if (this->ch != 102) {
        goto importError;
    }
    if (fgetc(this->fp) != 114) {
        goto importError;
    }
    if (fgetc(this->fp) != 111) {
        goto importError;
    }
    if (fgetc(this->fp) != 109) {
        goto importError;
    }

    RegexStrictSpaces(this);

    Memory(this);

    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                goto importError;
            case 10:
                goto importError;
            case 32:
               // END of script line
               while (1) {
                    switch (fgetc(this->fp)) {
                        default :
                             goto importError;
                        case 59:
                             MemoryMap(this);
                             return;
                    }
                }
            case 59:
                MemoryMap(this);
                return;
            default:
                Memory(this);
                break;
        }
    }
    
importError:
    Error(this,"import");
}