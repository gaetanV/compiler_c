module.exports = (function () {
    'use strict'
    const $parse = require('./parse.js');
    return class ecma6 extends $parse {
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
            str += "class " + this.funcName + "{\n";
            return str;
        }

        body() {
            let str = "";
            str += this.funcConstructor();
            str += this.funcPublic();
            str += this.funcStatic();
            str += this.funcReflect();
            return  str;
        }
        footer() {
            return "};\n" + "})();\n";
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
                str += a.name + "(" + a.args + "){\n" + a.content + "\n" + "}\n";
            });
            return str;
        }

        funcConstructor() {
            let str = "constructor (" + this.reflect.constructor.args.map(function (a, b) {
                return a[1];
            }) + "){\n";
            str += this.reflect.constructor.content;
            str += "\n" + "}\n";
            return str;
        }
        funcReflect(c) {
            let str = "static reflect(){\n";
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
            str += "\n" + "}\n";
            return str;
        }

    }
})();