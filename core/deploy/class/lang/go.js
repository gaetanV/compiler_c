module.exports = (function () {
    'use strict'
    const $class = require('./../class.js');
    const self = "this";
    return class go extends $class {

        constructor(funcName, file) {
            super(funcName, file);
        }

        build() {
            let str = "";
            str += this.inner();
            return str;
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