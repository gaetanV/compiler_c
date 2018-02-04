// No opti ( Exit code Only )

void Error(struct Buffer * buffer, char * message) {
    int cmp = 1;
    int pos = ftell(buffer->fp);
    fseek(buffer->fp, 0, SEEK_SET);
    int pointer;
    int tmp;

    while (1) {
        switch (fgetc(buffer->fp)) {
            case 10:
                cmp++;
                fgetc(buffer->fp);
                tmp = ftell(buffer->fp);
                pointer = tmp;
                break;
            default:
                tmp = ftell(buffer->fp);
                break;
        }
        if (tmp >= pos) {
            goto step2;
        }
    }
step2:
    fseek(buffer->fp, pointer -1 , SEEK_SET);
    printf("Fatal Error : %s \n\n", message);
    printf("Ligne %d \n", cmp);
    while (1) {
        switch (buffer->ch = fgetc(buffer->fp)) {
            case 10:
            case EOF:
                printf("\n");
                exit(0);
                break;
            default:
                printf("%c", buffer->ch);
                break;
        }
    }
}



