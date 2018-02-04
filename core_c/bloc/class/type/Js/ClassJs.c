
int ClassJs(
        struct Buffer * buffer, 
        int(classOuputType) (struct Buffer *, struct ClassCollectorJs * collector)
 ) {

    struct ClassCollectorJs * collector  =  newClassCollectorJs(buffer->_pointer - 2);
    
    CollectorExtends(buffer, &collector->hasExtends);

    
    while (1) {
        switch (buffer->ch = fgetc(buffer->fp)) {
            case 32:
                break;
            case 10:
                break;
            case 47:
                RegexStrictComments(buffer);
                break;
            case 99:
                if (RegexConstructorOrFunc(buffer)) {
                    CollectorContructorArgs(
                            buffer, 
                            &collector->hasConstructor ,
                            collector->constructor
                            );
                } else {
                    CollectorFuncNameArgs(
                            buffer,
                            &collector->_func,
                            collector->func
                            );
                }
                break;
            case 115:
                if (RegexStaticOrFunc(buffer)) {
                    RegexStrictSpaces(buffer);
                    CollectorFuncNameArgsOrAttr(
                            buffer,
                            &collector->_funcStatic,
                            collector->funcStatic,
                            &collector->_attrStatic,
                            collector->attrStatic
                            );

                } else {
                    CollectorFuncNameArgs(
                            buffer,
                            &collector->_func,
                            collector->func
                            );
                }
                break;
            default:
                CollectorFuncNameArgs(
                        buffer, &collector->_func,
                        collector->func
                        );
                break;
            case EOF:
                return 0;
            case 125:
                classOuputType(buffer, collector);
                return 1;

        }
    }
    return 0;
}
