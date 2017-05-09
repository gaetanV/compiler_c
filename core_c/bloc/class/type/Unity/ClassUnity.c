#include <stdio.h>

int ClassUnity(struct Buffer * this, struct ClassCollector * collector) {

    CollectorExtends(this, collector);

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
                    CollectorContructorArgsStrictType(this, collector);
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
                        CollectorFuncNameArgsOrAttrStrictType(
                                this,
                                &collector->_func,
                                collector->func,
                                &collector->_attrPublic,
                                collector->attrPublic
                                );
                        break;
                    case 114:
                        if (RegexRivateOrFunc(this)) {
                            RegexStrictSpaces(this);
                            CollectorFuncNameArgsOrAttrStrictType(
                                    this,
                                    &collector->_funcPrivate,
                                    collector->funcPrivate,
                                    &collector->_attrPrivate,
                                    collector->attrPrivate
                                    );
                        } else {
                            CollectorFuncNameArgsOrAttrStrictType(
                                    this,
                                    &collector->_func,
                                    collector->func,
                                    &collector->_attrPublic,
                                    collector->attrPublic
                                    );

                        }
                        break;
                    default:
                        CollectorFuncNameArgsOrAttrStrictType(
                                this,
                                &collector->_func,
                                collector->func,
                                &collector->_attrPublic,
                                collector->attrPublic
                                );
                        break;
                }
                break;
            case 115:
                if (RegexStaticOrFunc(this)) {
                    RegexStrictSpaces(this);
                }
                CollectorFuncNameArgsOrAttrStrictType(
                        this,
                        &collector->_funcStatic,
                        collector->funcStatic,
                        &collector->_attrStatic,
                        collector->attrStatic
                        );
                break;
            default:
                CollectorFuncNameArgsOrAttrStrictType(
                        this,
                        &collector->_func,
                        collector->func,
                        &collector->_attrPublic,
                        collector->attrPublic
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
