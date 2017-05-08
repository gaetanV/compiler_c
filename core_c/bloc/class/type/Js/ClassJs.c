int ClassJs(struct sequenceRegex * this, struct ClassCollector * collector) {

    CollectorExtends(this,collector);

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
                    CollectorContructorArgs(this,collector);
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
                    if (!RegexJumpSpace(this)) {
                        return 0;
                    }
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
                return 1;

        }
    }
    return 0;
}
