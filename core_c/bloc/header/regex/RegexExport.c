/**
@ERROR
*/
void ErrorHeaderExport(struct Buffer * this) {
    Error(this, "Contructor arguments type");
}

/**
@@@@@@@
*/
void RegexStrictExport(struct Buffer * this) {

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


    return;

}