module.exports = (function () {
    'use strict'
    const $ts = require("typescript");
    const $class = require('./../class.js');

    return class ecma5 extends $class {

        inner() {
            var str = "";
            str += this.funcConstructor();
            str += this.funcPublic();
            str += this.funcPrivate();
            return  str;
        }
        
        funcConstructor() {
            var str = `var ${this.funcName} = function (args){\n`;
            for (var i in this.reflect.constructor.args) {
                str += `var ${i} = args.${i};\n`;
            }
            str += `${this.parseEcma5(this.reflect.constructor.content)}\n }\n`;
            return str;
        }

        funcPublic() {
            var str = "";
            this.reflect.public.every(function (a, b) {
                str += `${this.funcName}.prototype.${a.name} = function(${a.args}){\n${this.parseEcma5(a.content)}\n}\n`;
            }.bind(this));
            return str;
        }

        funcPrivate() {
            var str = "";
            this.reflect.private.every(function (a, b) {
                str += `${this.funcName}.prototype.${a.name} = function (${a.args}){\n${this.parseEcma5(a.content)}\n}\n`;
            }.bind(this));
            return str;
        }

        parseEcma5(string) {

            let result = $ts.transpileModule(`${string}`, {compilerOptions: {module: $ts.ModuleKind.CommonJS}});
            return  result.outputText.replace("exports.__esModule = true;", "").replace('"use strict";',"");
        }

    }
})();