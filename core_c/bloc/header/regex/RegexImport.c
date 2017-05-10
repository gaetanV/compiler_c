/**
@ERROR
*/
void ErrorHeaderImport(struct Buffer * this) {
    Error(this, "Error Only one Constructor");
}


/**
@@@@@@@
*/
void RegexStrictImport(struct Buffer * this) {

    // REGEX IMPORT Start at 105
    if (fgetc(this->fp) != 109) {
        ErrorHeaderImport(this);
    }
    if (fgetc(this->fp) != 112) {
        ErrorHeaderImport(this);
    }
    if (fgetc(this->fp) != 111) {
        ErrorHeaderImport(this);
    }
    if (fgetc(this->fp) != 114) {
        ErrorHeaderImport(this);
    }
    if (fgetc(this->fp) != 116) {
        ErrorHeaderImport(this);
    }

    RegexStrictSpaces(this);

    // REGEX NotSpaceInline
    Memory(this);
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                ErrorHeaderImport(this);
            case 10:
                ErrorHeaderImport(this);
            case 59:
                ErrorHeaderImport(this);
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
        ErrorHeaderImport(this);
    }
    if (fgetc(this->fp) != 114) {
        ErrorHeaderImport(this);
    }
    if (fgetc(this->fp) != 111) {
        ErrorHeaderImport(this);
    }
    if (fgetc(this->fp) != 109) {
        ErrorHeaderImport(this);
    }

    RegexStrictSpaces(this);

    Memory(this);

    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case EOF:
                ErrorHeaderImport(this);
            case 10:
                ErrorHeaderImport(this);
            case 32:
                // END of script line
                while (1) {
                    switch (fgetc(this->fp)) {
                        default:
                            ErrorHeaderImport(this);
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


}