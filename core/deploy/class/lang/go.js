module.exports = (function () {
    'use strict'
    const $class = require('./../class.js');
    const self = "this";
    return class go extends $class {
        
        constructor(funcName, file) {
            super(funcName, file);
        }
        
        build(namespace) {
            let str = "";
            str += this.inner();
            return str;
        }
        inner() {
            let str = "";
            str += this.funcStruct();
            str += this.funcConstructor();
            str += this.funcPublic();
            return  str;
        }
        
        funcStruct(){
            let str = "";
            var a = this.reflect.constructor;
            str += `type ${this.funcName}struct {\n`;
            for(var i in a.args){
                 str+= `${i} ${a.args[i]}\n`;
            }
            str += `}\n`
            return str;
        }
        
        funcPublic() {
            let str = "";
            let d = this.funcName;
            this.reflect.public.every(function (a, b) {
                str += `func (${self} *${d}) (${a.args}){\n${a.content}\n}\n`;
            });
            return str;
        }
        
        funcConstructor() {
            let a = this.reflect.constructor;
            let args = "";
            for(var i in a.args){
                args += `${i} ${a.args[i]} `
            }
            let str = "";
            str += `func new${this.funcName} (${args}){\n${a.content}\n}\n`;
            return str;
        }
        
    }  
})();