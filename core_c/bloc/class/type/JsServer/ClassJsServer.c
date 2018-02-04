
int ClassJsServer(
        struct Buffer * buffer, 
        int(classOuputType) (struct Buffer *, struct ClassCollectorJsServer * collector)
 ) {

    struct ClassCollectorJsServer * collector  =  newClassCollectorJsServer(buffer->_pointer - 2);


    CollectorExtendsImplements(buffer, &collector->hasExtends, &collector->hasImplements );

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
                    CollectorContructorArgsType(
                            buffer, 
                            collector->constructor,
                            &collector->hasConstructor ,
                            &collector->_type , 
                            collector->type);

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
            case 112:
                switch (fgetc(buffer->fp)) {
                    case 117:
                        if (RegexUblicOrFunc(buffer)) {
                            RegexStrictSpaces(buffer);
                        }
                        CollectorFuncNameArgs(
                                buffer,
                                &collector->_func,
                                collector->func
                                );
                        break;
                    case 114:
                        if (RegexRivateOrFunc(buffer)) {
                            RegexStrictSpaces(buffer);
                            CollectorFuncNameArgsOrAttr(
                                    buffer,
                                    &collector->_funcPrivate,
                                    collector->funcPrivate,
                                    &collector->_attrPrivate,
                                    collector->attrPrivate
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
                }
                break;
            default:
                CollectorFuncNameArgs(
                        buffer, 
                        &collector->_func,
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
