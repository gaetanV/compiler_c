void RegexStrictExport(struct Buffer * this) {

    // REGEX EXPORT start at 101
    if (fgetc(this->fp) != 120) {
        goto exportError;
    }
    if (fgetc(this->fp) != 112) {
        goto exportError;
    }
    if (fgetc(this->fp) != 111) {
        goto exportError;
    }
    if (fgetc(this->fp) != 114) {
        goto exportError;
    }
    if (fgetc(this->fp) != 116) {
        goto exportError;
    }

    RegexStrictSpaces(this);


    return;

exportError:
    Error(this, "export");
}