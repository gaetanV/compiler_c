module.exports = (function () {
    'use strict'
    const $parse = require('./parse.js');
    return class ecma5 extends $parse {
        constructor(funcName, file) {
            super(funcName, file);
        }

        build(namespace) {
            let str = "";
            str += this.header(namespace);
            str += this.body();
            str += this.footer();
            return str;
        }

        header(namespace) {
            let str = "";
            str += "(function () {\n"
            str += "'use strict';\n";
            str += "autoload('" + namespace + "').class('" + this.funcName + "', " + this.funcName + ", " + JSON.stringify(this.reflect.constructor.args) + ");\n";
            return str;
        }

        body() {
            let str = "";
            str += this.funcConstructor();
            str += this.funcPublic();
            return  str;
        }
        footer() {
            return "})();\n";
        }
        funcStatic() {
            let str = "";
            this.reflect.static.every(function (a, b) {
                str += "static " + a.name + "(" + a.args + "){\n" + a.content + "\n" + "}\n";
            });
            return str;
        }

        funcPublic() {
            let str = "";
            this.reflect.public.every(function (a, b) {
                str += this.funcName + ".prototype." + a.name + " = function(" + a.args + "){\n" + a.content + "\n" + "}\n";
            }.bind(this));
            return str;
        }

        funcConstructor() {
            let str = "";
            str += "function " + this.funcName + "(" + this.reflect.constructor.args.map(function (a, b) {
                return a[1];
            }) + "){\n";
            str += this.reflect.constructor.content;
            str += "\n" + "}\n";
            return str;
        }

    }
})();