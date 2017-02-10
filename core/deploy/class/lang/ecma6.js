module.exports = (function () {
    'use strict'
    const $class = require('./../class.js');
    return class ecma6 extends $class {
        constructor(funcName, file) {
            super(funcName, file);
        }

        build(namespace) {
            let str = "";
            str += `register('${namespace}').class('${this.funcName}', `,
            str += `class {\n`;
            str += this.inner();
            str += `}\n`;
            str += `,${JSON.stringify(this.reflect.constructor.args)});\n`;
            console.log(this.reflect.constructor.args);
            return str;
        }

        inner() {
            let str = "";
            str += this.funcConstructor();
            str += this.funcPublic();
            str += this.funcStatic();
            str += this.funcReflect();
            return  str;
        }
       
        funcStatic() {
            let str = "";
            this.reflect.static.every(function (a, b) {
                str += `static ${a.name} (${a.args}){\n${a.content}\n}\n`;
            });
            return str;
        }

        funcPublic() {
            let str = "";
            this.reflect.public.every(function (a, b) {
                str += `${a.name} (${a.args}){\n${a.content}\n}\n`;
            });
            return str;
        }

        funcConstructor() {
            let str = "constructor (args){\n";
            for(var i in this.reflect.constructor.args){
                 str+= `let ${i} = args.${i};\n`;
            }
           
            str += this.reflect.constructor.content;
            str += `\n }\n`;
            return str;
        }
        funcReflect(c) {
            let str = `static reflect(){\n`;
            let cr = this.reflect.constructor;
            let constructor = {
                type: cr.type,
                name: cr.name,
                args: cr.args
            }
            str += "return " + JSON.stringify(
                    this.reflect.public.map(function (a, b) {
                        return {type: a.type, name: a.name, args: a.args}
                    })
                    .concat(
                            this.reflect.static.map(function (a, b) {
                                return {type: a.type, name: a.name, args: a.args}
                            })
                            ).concat(
                    this.reflect.private.map(function (a, b) {
                        return {type: a.type, name: a.name, args: a.args}
                    })
                    ).concat(
                    [constructor]
                    )
                    );
            str += `\n }\n`;
            return str;
        }

    }
})();