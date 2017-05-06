void RegexStrictComments(struct sequenceRegex * this) {
    switch (fgetc(this->fp)) {
        case 47:
            if (!RegexForceEmptyLigne(this)) {
                goto errorComments;
            }
            return;
            break;
        case 42:
            if (!RegexCommentBloc(this)) {
                goto errorComments;
            }
            return;
            break;
        default:
            goto errorComments;
    }
errorComments:
    printf("error in comments");
    exit(0);
}

