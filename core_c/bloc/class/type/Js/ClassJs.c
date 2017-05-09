
int ClassJs(
        struct Buffer * this, 
        int(classOuputType) (struct Buffer *, struct ClassCollectorJs * collector)
 ) {

    struct ClassCollectorJs * collector  =  newClassCollectorJs(this->_pointer - 2);
    
    CollectorExtends(this, &collector->hasExtends);


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
                    CollectorContructorArgs(
                            this, 
                            &collector->hasConstructor ,
                            collector->constructor
                            );
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
            default:
                CollectorFuncNameArgs(
                        this, &collector->_func,
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
