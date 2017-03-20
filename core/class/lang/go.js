module.exports = (function () {
    'use strict'
    
    const $class = require('./../class.js');
    const self = "this";

    return class go extends $class {
        
        constructor(funcName, file) {
            super(funcName, file);
        }
        
        build() {
            return this.inner();
        }
  
        inner() {
            var str = "";
            str += this.funcStruct();
            str += this.funcConstructor();
            str += this.funcPublic();
            str += this.funcGetter();
            str += this.funcSetter();
            return  str;
        }
        
        funcGetter() {
            var str = "";
            for (var i in this.interface.public) {
                str += `func (${self} *${this.funcName}) get${i}()(*${this.interface.public[i]})  {\nreturn &this.${i}\n}\n`;
            }
            return str;
        }
        
        funcSetter() {
            var str = "";
            for (var i in this.interface.public) {
                str += `func (${self} *${this.funcName}) set${i}(${i} ${this.interface.public[i]})  {\nthis.${i} = ${i}\n}\n`;
            }
            return str;
        }
        
        funcStruct() {
            var str = "";
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
            this.reflect.public.every(function (a) {
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
            var str = "";
            this.reflect.public.every(function (a, b) {
                str += `func (${self} *${this.funcName}) ${a.name}(${a.args}) (${a.return}){\n${a.content}\n}\n`;
            }.bind(this));
            return str;
        }

        funcConstructor() {
            var str = "", priv = "", args = "", rc = this.reflect.constructor;
            for (var i in rc.args) {
                args += `${rc.args[i]} ${i}`
            }
            this.reflect.private.every(function (a) {
                priv += `this.${a.name} = func(${a.args})(${a.return}){\n${a.content}\n}\n`;
            })
            str += `func new${this.funcName} (${args})  ${this.funcName}Interface{\nthis := new(${this.funcName})\n${priv}\n${rc.content}\nreturn this\n}\n`;
            return str;
        }
    }
})();