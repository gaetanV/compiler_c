/**
@ERROR
 */
void ErrorHeaderExport(struct Buffer * this) {
    Error(this, "Contructor arguments type");
}

void ErrorHeaderImport(struct Buffer * this) {
    Error(this, "Error Only one Constructor");
}

int parseHeader(struct Buffer * this) {

    this->import = 0;
    MemoryMap(this);
    while (1) {
        switch (fgetc(this->fp)) {
            case EOF:
                return 0;
            case 105:

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
                                        goto step3;
                                }
                            }
                        case 59:
                            MemoryMap(this);
                           goto step3;
                        default:
                            Memory(this);
                            break;
                    }
                }
step3:              
                this->import++;
                break;
            case 101:
                // REGEX EXPORT start at 101
                if (fgetc(this->fp) != 120) {
                    ErrorHeaderExport(this);
                }
                if (fgetc(this->fp) != 112) {
                    ErrorHeaderExport(this);
                }
                if (fgetc(this->fp) != 111) {
                    ErrorHeaderExport(this);
                }
                if (fgetc(this->fp) != 114) {
                    ErrorHeaderExport(this);
                }
                if (fgetc(this->fp) != 116) {
                    ErrorHeaderExport(this);
                }

                RegexStrictSpaces(this);

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

