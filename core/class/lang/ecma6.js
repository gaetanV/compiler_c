module.exports = (function () {
    'use strict'
    const $class = require('./../class.js');
    return class ecma6 extends $class {
        
        constructor(funcName, file) {
            super(funcName, file);
        }

        build(namespace) {
            return `class ${this.funcName}{\n${this.inner()}\n};\n`;
        }

        inner() {
            var str = "";
            str += this.funcConstructor();
            str += this.funcPublic();
            str += this.funcStatic();
            str += this.funcReflect();
            return  str;
        }

        funcStatic() {
            var str = "";
            this.reflect.static.every(function (a, b) {
                str += `static ${a.name} (${a.args}){\n${a.content}\n}\n`;
            });
            return str;
        }

        funcPublic() {
            var str = "";
            this.reflect.public.every(function (a, b) {
                str += `${a.name} (${a.args}){\n${a.content}\n}\n`;
            });
            return str;
        }

        funcConstructor() {
            var str = "constructor (args){\n";
            for (var i in this.reflect.constructor.args) {
                str += `let ${i} = args.${i};\n`;
            }
            str += `${this.reflect.constructor.content}\n }\n`;
            return str;
        }
        
        funcReflect() {
            var str = `static reflect(){\n`;
            var cr = this.reflect.constructor;
            str += "return " + JSON.stringify(
                this.reflect.public
                .map(function (a) {
                    return {type: a.type, name: a.name, args: a.args}
                })
                .concat(
                    this.reflect.static.map(function (a) {
                        return {type: a.type, name: a.name, args: a.args}
                    })
                )
                .concat(
                    this.reflect.private.map(function (a) {
                        return {type: a.type, name: a.name, args: a.args}
                    })
                ).concat(
                    [{type: cr.type, name: cr.name, args: cr.args}]
                )
            );
            str += `\n }\n`;
            return str;
        }
    }
})();