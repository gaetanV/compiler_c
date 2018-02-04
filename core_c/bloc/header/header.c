/**
@ERROR
 */
void ErrorHeaderExport(struct Buffer * buffer) {
    Error(buffer, "Contructor arguments type");
}

void ErrorHeaderImport(struct Buffer * buffer) {
    Error(buffer, "Error Only one Constructor");
}

int parseHeader(struct Buffer * buffer) {

    buffer->import = 0;
    MemoryMap(buffer);
    while (1) {
        switch (fgetc(buffer->fp)) {
            case EOF:
                return 0;
            case 105:

                // REGEX IMPORT Start at 105
                if (fgetc(buffer->fp) != 109) {
                    ErrorHeaderImport(buffer);
                }
                if (fgetc(buffer->fp) != 112) {
                    ErrorHeaderImport(buffer);
                }
                if (fgetc(buffer->fp) != 111) {
                    ErrorHeaderImport(buffer);
                }
                if (fgetc(buffer->fp) != 114) {
                    ErrorHeaderImport(buffer);
                }
                if (fgetc(buffer->fp) != 116) {
                    ErrorHeaderImport(buffer);
                }

                RegexStrictSpaces(buffer);

                // REGEX NotSpaceInline
                Memory(buffer);
                while (1) {
                    switch (buffer->ch = fgetc(buffer->fp)) {
                        case EOF:
                            ErrorHeaderImport(buffer);
                        case 10:
                            ErrorHeaderImport(buffer);
                        case 59:
                            ErrorHeaderImport(buffer);
                        case 32:
                            goto step2;
                        default:
                            Memory(buffer);
                            break;
                    }
                }
step2:
                MemoryMap(buffer);
                RegexJumpSpace(buffer);

                // REGEX FROM

                if (buffer->ch != 102) {
                    ErrorHeaderImport(buffer);
                }
                if (fgetc(buffer->fp) != 114) {
                    ErrorHeaderImport(buffer);
                }
                if (fgetc(buffer->fp) != 111) {
                    ErrorHeaderImport(buffer);
                }
                if (fgetc(buffer->fp) != 109) {
                    ErrorHeaderImport(buffer);
                }

                RegexStrictSpaces(buffer);

                Memory(buffer);

                while (1) {
                    switch (buffer->ch = fgetc(buffer->fp)) {
                        case EOF:
                            ErrorHeaderImport(buffer);
                        case 10:
                            ErrorHeaderImport(buffer);
                        case 32:
                            // END of script line
                            while (1) {
                                switch (fgetc(buffer->fp)) {
                                    default:
                                        ErrorHeaderImport(buffer);
                                    case 59:
                                        MemoryMap(buffer);
                                        goto step3;
                                }
                            }
                        case 59:
                            MemoryMap(buffer);
                           goto step3;
                        default:
                            Memory(buffer);
                            break;
                    }
                }
step3:              
                buffer->import++;
                break;
            case 101:
                // REGEX EXPORT start at 101
                if (fgetc(buffer->fp) != 120) {
                    ErrorHeaderExport(buffer);
                }
                if (fgetc(buffer->fp) != 112) {
                    ErrorHeaderExport(buffer);
                }
                if (fgetc(buffer->fp) != 111) {
                    ErrorHeaderExport(buffer);
                }
                if (fgetc(buffer->fp) != 114) {
                    ErrorHeaderExport(buffer);
                }
                if (fgetc(buffer->fp) != 116) {
                    ErrorHeaderExport(buffer);
                }

                RegexStrictSpaces(buffer);

                return 1;
            case 47:
                RegexStrictComments(buffer);
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

