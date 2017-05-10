
int ClassJsServer(
        struct Buffer * this, 
        int(classOuputType) (struct Buffer *, struct ClassCollectorJsServer * collector)
 ) {

    struct ClassCollectorJsServer * collector  =  newClassCollectorJsServer(this->_pointer - 1);


    CollectorExtendsImplements(this, &collector->hasExtends, &collector->hasImplements );

    while (1) {
        switch (this->ch = fgetc(this->fp)) {
            case 32:
                break;
            case 10:
                break;
            case 47:
                RegexStrictComments(this);
                break;
            case 99:
                if (RegexConstructorOrFunc(this)) {
                    CollectorContructorArgsType(
                            this, 
                            collector->constructor,
                            &collector->hasConstructor ,
                            &collector->_type , 
                            collector->type);

                } else {
                    CollectorFuncNameArgs(
                            this,
                            &collector->_func,
                            collector->func
                            );
                }
                break;
            case 115:
                if (RegexStaticOrFunc(this)) {
                    RegexStrictSpaces(this);
                    CollectorFuncNameArgsOrAttr(
                            this,
                            &collector->_funcStatic,
                            collector->funcStatic,
                            &collector->_attrStatic,
                            collector->attrStatic
                            );

                } else {

                    CollectorFuncNameArgs(
                            this,
                            &collector->_func,
                            collector->func
                            );
                }
                break;
            case 112:
                switch (fgetc(this->fp)) {
                    case 117:
                        if (RegexUblicOrFunc(this)) {
                            RegexStrictSpaces(this);
                        }
                        CollectorFuncNameArgs(
                                this,
                                &collector->_func,
                                collector->func
                                );
                        break;
                    case 114:
                        if (RegexRivateOrFunc(this)) {
                            RegexStrictSpaces(this);
                            CollectorFuncNameArgsOrAttr(
                                    this,
                                    &collector->_funcPrivate,
                                    collector->funcPrivate,
                                    &collector->_attrPrivate,
                                    collector->attrPrivate
                                    );
                        } else {
                            CollectorFuncNameArgs(
                                    this,
                                    &collector->_func,
                                    collector->func
                                    );

                        }
                        break;
                    default:
                        CollectorFuncNameArgs(
                                this, &collector->_func,
                                collector->func
                                );
                        break;
                }
                break;
            default:
                CollectorFuncNameArgs(
                        this, 
                        &collector->_func,
                        collector->func
                        );
                break;

            case EOF:
                return 0;
            case 125:
                classOuputType(this, collector);
                return 1;

        }
    }

    return 0;
}
