#include <stdio.h>

int ClassUnity(
        struct Buffer * buffer,
        int(classOuputType) (struct Buffer *, struct ClassCollectorUnity * collector)
        ) {

    struct ClassCollectorUnity * collector = newClassCollectorUnity(buffer->_pointer - 2);
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
                    CollectorContructorArgsStrictType(
                            buffer,
                            &collector->hasConstructor,
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
            case 112:
                switch (fgetc(buffer->fp)) {
                    case 117:
                        if (RegexUblicOrFunc(buffer)) {
                            RegexStrictSpaces(buffer);
                        }
                        CollectorFuncNameArgsOrAttrStrictType(
                                buffer,
                                &collector->_func,
                                collector->func,
                                &collector->_attrPublic,
                                collector->attrPublic
                                );
                        break;
                    case 114:
                        if (RegexRivateOrFunc(buffer)) {
                            RegexStrictSpaces(buffer);
                            CollectorFuncNameArgsOrAttrStrictType(
                                    buffer,
                                    &collector->_funcPrivate,
                                    collector->funcPrivate,
                                    &collector->_attrPrivate,
                                    collector->attrPrivate
                                    );
                        } else {
                            CollectorFuncNameArgsOrAttrStrictType(
                                    buffer,
                                    &collector->_func,
                                    collector->func,
                                    &collector->_attrPublic,
                                    collector->attrPublic
                                    );

                        }
                        break;
                    default:
                        CollectorFuncNameArgsOrAttrStrictType(
                                buffer,
                                &collector->_func,
                                collector->func,
                                &collector->_attrPublic,
                                collector->attrPublic
                                );
                        break;
                }
                break;
            case 115:
                if (RegexStaticOrFunc(buffer)) {
                    RegexStrictSpaces(buffer);
                    CollectorFuncNameArgsOrAttrStrictType(
                            buffer,
                            &collector->_funcStatic,
                            collector->funcStatic,
                            &collector->_attrStatic,
                            collector->attrStatic
                            );

                } else {
                    CollectorFuncNameArgsOrAttrStrictType(
                            buffer,
                            &collector->_func,
                            collector->func,
                            &collector->_attrPublic,
                            collector->attrPublic
                            );
                }
                break;
            default:
                CollectorFuncNameArgsOrAttrStrictType(
                        buffer,
                        &collector->_func,
                        collector->func,
                        &collector->_attrPublic,
                        collector->attrPublic
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
