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
            return  str;
        }
        
        funcStruct(){
            let str = "";
            str += `type ${this.funcName} struct {\n`;
            for(var i in this.interface){
                 str+= `${i} ${this.interface[i]}\n`;
            }
            str += `}\n`
            
            str += `type ${this.funcName}Interface interface {\n`;      
            this.reflect.public.every(function (a, b) {
                   str +=  `${a.name}(${a.args})\n`
            });
            str += `}\n`
            return str;
        }
        
        funcPublic() {
            let str = "";
            let d = this.funcName;
            this.reflect.public.every(function (a, b) {
                str += `func (${self} *${d}) ${a.name}(${a.args}){\n${a.content}\n}\n`;
            });
            return str;
        }
        
        funcConstructor() {
            let a = this.reflect.constructor;
            let args = "";
            for(var i in a.args){
                args += `${a.args[i]} ${i}`
            }
    
            return `func new${this.funcName} (${args})  ${this.funcName}Interface{\nthis := new(${this.funcName})\n${a.content}\nreturn this\n}\n`;
        }
        
    }  
})();