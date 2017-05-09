#include <stdio.h>

int ClassUnity(
        struct Buffer * this,
        int(classOuputType) (struct Buffer *, struct ClassCollectorUnity * collector)
        ) {

    struct ClassCollectorUnity * collector = newClassCollectorUnity(this->_pointer - 2);
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
                    CollectorContructorArgsStrictType(
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
                classOuputType(this, collector);
                return 1;
        }
    }
    return 0;
}
