module.exports = (function () {
    'use strict'
    const $class = require('./../class.js');
    const self = "this";
    const REGEX = {
        command: "{%([\x00-\x7E]*)%}([\x00-\x7E]*){%([\x00-\x7E]*)%}",
        operator: "(if)([^=<>]*)([=<>]*)(.*)"
    }

    return class go extends $class {
        constructor(funcName, file) {
            super(funcName, file);
        }

        build() {
            let str = "";
            str += this.inner();
            return str;
        }
        buildTemplate(scope, method) {
            var factory = {public: [], private: [], static: [], constructor: this.reflect.constructor}
            delete this.reflect.constructor;

            var apply = (string, scope) => {
                for (var i in  scope) {
                    string = string.replace(new RegExp(`{{${i}}}`, 'g'), scope[i]);
                }
                return string;
            };
            var compile = (string, scope) => {
                var m = new RegExp(REGEX.command, "g"), match, operator;
                do {
                    operator = false;
                    match = m.exec(string);
                    if (match) {
                        var start = match.index + match[1].length + 4;
                        var end = start + match[2].length;

                        var content = string.slice(start, end);

                        var tmp = RegExp(REGEX.operator, "g").exec(match[1]);

                        switch (tmp[1]) {
                            case "if":
                                var t1 = tmp[2].trim()
                                var t2 = scope[t1]
                                if (t2) {
                                    var func = "return " + tmp[2] + tmp[3] + tmp[4];
                                    if (new Function(t1, func)(t2)) {
                                        operator = true;
                                    }
                                }
                                break
                        }
                        if (operator) {
                            string = string.replace(match[0], content);
                        } else {
                            string = string.replace(match[0], "");
                        }
                    }
                } while (match)
                return string;
            }

            for (var i in this.reflect) {
                for (var j in this.reflect[i]) {
                    if (method.indexOf(j)) {
                        for (var k in  this.reflect[i][j].return) {
                            this.reflect[i][j].return[k] = apply(this.reflect[i][j].return[k], scope);
                        }
                        var c = apply(this.reflect[i][j].content, scope);
                        this.reflect[i][j].content = compile(c, scope);
                        factory[i][j] = this.reflect[i][j];
                    }
                }
            }

            this.reflect = factory;
            return this.build();
        }
        inner() {
            let str = "";
            str += this.funcStruct();
            str += this.funcConstructor();
            str += this.funcPublic();
            str += this.funcGetter();
            str += this.funcSetter();
            return  str;
        }
        funcGetter() {
            let str = "";
            let d = this.funcName;

            for (var i in this.interface.public) {
                str += `func (${self} *${this.funcName}) get${i}()(*${this.interface.public[i]})  {\nreturn &this.${i}\n}\n`;
            }
            return str;
        }
        funcSetter() {
            let str = "";
            for (var i in this.interface.public) {
                str += `func (${self} *${this.funcName}) set${i}(${i} ${this.interface.public[i]})  {\nthis.${i} = ${i}\n}\n`;
            }
            return str;
        }
        funcStruct() {
            let str = "";
            str += `type ${this.funcName} struct {\n`;
            for (var i in this.interface) {
                switch (i) {
                    case "public":
                        for (var j in this.interface[i]) {
                            str += `${j} ${this.interface[i][j]}\n`;
                        }
                        break;
                    case "private":
                        for (var j in this.interface[i]) {
                            str += `${j} ${this.interface[i][j]}\n`;
                        }
                        break;
                }
            }
            this.reflect.private.every(function (a) {
                str += `${a.name} func(${a.args}) (${a.return})\n`;
            });
            str += `}\n`

            str += `type ${this.funcName}Interface interface {\n`;
            this.reflect.public.every(function (a, b) {
                str += `${a.name}(${a.args})(${a.return})\n`
            });
            for (var i in this.interface.public) {
                str += `get${i}()(*${this.interface.public[i]})\n`;
                str += `set${i}(${i} ${this.interface.public[i]})\n`;
            }
            str += `}\n`
            return str;
        }

        funcPublic() {
            let str = "";
            let d = this.funcName;
            this.reflect.public.every(function (a, b) {
                str += `func (${self} *${d}) ${a.name}(${a.args}) (${a.return}){\n${a.content}\n}\n`;
            });
            return str;
        }

        funcConstructor() {
            let str = "";
            let a = this.reflect.constructor;
            let args = "";
            for (var i in a.args) {
                args += `${a.args[i]} ${i}`
            }
            let priv = "";
            this.reflect.private.every(function (a) {
                priv += `this.${a.name} = func(${a.args})(${a.return}){\n${a.content}\n}\n`;
            })
            str += `func new${this.funcName} (${args})  ${this.funcName}Interface{\nthis := new(${this.funcName})\n${priv}\n${a.content}\nreturn this\n}\n`;
            return str
        }

    }
})();