void RegexStrictImport(struct sequenceRegex * this) {

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

    if (!RegexJumpSpace(this)) {
        goto importError;
    }

    if (!RegexMemoryNotSpaceInline(this)) {
        goto importError;
    }

    MemoryMap(this);

    if (!RegexJumpSpace(this)) {
        goto importError;
    }
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

    if (!RegexJumpSpace(this)) {
        goto importError;
    }

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
    printf("Error in Import  \n");
    exit(0);
}