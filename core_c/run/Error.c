// No opti ( Exit code Only )

void Error(struct Buffer * this, char * message) {
    int cmp = 1;
    int pos = ftell(this->fp);
    fseek(this->fp, 0, SEEK_SET);
    int pointer;
    int tmp;
step1:
    while (1) {
        switch (fgetc(this->fp)) {
            case 10:
                cmp++;
                fgetc(this->fp);
                tmp = ftell(this->fp);
                pointer = tmp;
                break;
            default:
                tmp = ftell(this->fp);
                break;
        }
        if (tmp >= pos) {
            goto step2;
        }
    }
step2:
    fseek(this->fp, pointer -1 , SEEK_SET);
    printf("Fatal Error : %s \n\n", message);
    printf("Ligne %d \n", cmp);
    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case 10:
            case EOF:
                printf("\n", cmp);
                exit(0);
                break;
            default:
                printf("%c", this->ch);
                break;
        }
    }
}



