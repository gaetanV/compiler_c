int RegexExport(struct sequenceRegex * this) {

    // REGEX EXPORT start at 101
    if (fgetc(this->fp) != 120) {
        return 0;
    }
    if (fgetc(this->fp) != 112) {
        return 0;
    }
    if (fgetc(this->fp) != 111) {
        return 0;
    }
    if (fgetc(this->fp) != 114) {
        return 0;
    }
    if (fgetc(this->fp) != 116) {
        return 0;
    }


    if (!RegexJumpSpace(this)) {
        return 0;
    }


    return 1;
}