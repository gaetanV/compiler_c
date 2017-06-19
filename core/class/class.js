

module.exports = (function () {
    'use strict'
    const REGEX = {
        import: "import[^\{]*{([^\}]*)}[^f]*from([^;]*)",
        export: "export[\\s]*class[\\s]*${func}[\\s]*([^\{]*)\{",
        interface: "interface[^\{]*{([^\}]*)}",
        interfaceInner: "[\r\n]*(private[\\s]*|static[\\s]*|public[\\s]*)([^\:]*):([^\;]*);",
        reflect: "(private[\\s]*|static[\\s]*|public[\\s]*|constructor[\\s]*)([^\(]*)\\(([^\)]*)\\)(.*)[\{]{1}"
    }

    return class Class {

        constructor(funcName, file) {

            var format = REGEX.export.replace("${func}", funcName);

            var match = new RegExp(format, "g").exec(file);
            if (!match)
                throw "ERROR " + this.funcName + " CLASS IS NOT CORRECTLY DEFINED";

            var pointer = match.index + match[0].length;
            var map = [], current = [], end = false, d;

            Class.getBracket(file).map(function (a, b) {
                switch (a) {
                    case 1:
                        current.push(b);
                        break;
                    case - 1:
                        d = current.pop();
                        if (d > (pointer) && !end) {
                            map[d - (pointer)] = b - (pointer)
                        }
                        pointer - 1 === d && (end = b);
                        break
                }
            });

            this.funcName = funcName;
            this.interface = Class.getInterface(file);
            this.content = file.slice(pointer, end);
            this.index = map;
            this.inject = Class.getImport(file);
            this.reflect = this.getReflect(this.content);

        }

        buildTemplate(method) {
            var factory = {
                public: [],
                private: [],
                static: [],
                constructor: this.reflect.constructor
            };
            delete this.reflect.constructor;
            for (var i in this.reflect) {
                for (var j in this.reflect[i]) {
                    if (method.indexOf(this.reflect[i][j].name.trim()) !== -1) {
                        factory[i][j] = this.reflect[i][j];
                    }
                }
            }
            this.reflect = factory;
            return this.build();
        }

        getReflect(c) {
            var inject = {
                public: [],
                private: [],
                static: [],
                constructor: {}
            };
            var m = new RegExp(REGEX.reflect, "g"), match, args, type;

            do {
                match = m.exec(c);
                if (match) {
                    args = Class.parseArrayFunc(match[3]);
                    var index = {
                        start: match.index,
                        end: match.index + match[0].length
                    };
                    type = match[1].trim();

                    var result = {
                        type: type,
                        return: match[4].trim().replace("(", "").replace(")", "").split(","),
                        content: this.content.slice(index.end, this.index[index.end - 1]).trim(),
                        index: index, argsText: match[3],
                        name: match[2],
                        args: args
                    };
                    switch (type) {
                        case "constructor":
                            let t = {};
                            args.map(function (a) {
                                var c = a.trim().split(" ");
                                if (c[0] && c[1]) {
                                    t[c[1]] = c[0];
                                } else {
                                    throw "error";
                                }
                            });
                            result.args = t;
                            inject.constructor = result;
                            break;
                        case "static":
                        case "public":
                        case "private":
                            inject[type].push(result);
                            break;
                    }
                }
            } while (match);
            return inject;
        }

        static parseArrayFunc(txt) {
            return txt.split(",").map(function (arg) {
                return arg.replace(/\/\*.*\*\//, '').trim();
            }).filter(function (arg) {
                return arg;
            });
        }

        static getBracket(file) {
            var closure = [];
            function getAllIndexes(arr, val, indexMin) {
                let indexes = [], i = -1;
                while ((i = arr.indexOf(val, i + 1)) !== -1) {
                    if (i >= indexMin)
                        indexes.push(i);
                }
                return indexes;
            }
            getAllIndexes(file, "{", 0).map(function (a) {
                closure[a] = 1;
            });
            getAllIndexes(file, "}", 0).map(function (a) {
                closure[a] = -1;
            });
            return closure;
        }

        static  getImport(file) {
            var inject = [], m = new RegExp(REGEX.import, "g"), tmp;
            do {
                tmp = m.exec(file);
                if (tmp) {
                    tmp[1] = tmp[1].replace(new RegExp(`['|"]`, 'g'), "").trim();
                    tmp[2] = tmp[2].replace(new RegExp(`['|"]`, 'g'), "").trim();
                    inject.push({name: tmp[1], space: tmp[2]});
                }
            } while (tmp);
            return inject;
        }

        static  getInterface(file) {
            var m = new RegExp(REGEX.interface, "g"), inner = new RegExp(REGEX.interfaceInner, "g");
            var interfaces = {
                private: {},
                public: {}
            };
            var tmp = m.exec(file), tmp2;
            if (tmp) {
                do {
                    tmp2 = inner.exec(tmp[1]);
                    if (tmp2) {
                        switch (tmp2[1].trim()) {
                            case "private":
                                interfaces.private[tmp2[2].trim()] = tmp2[3].trim();
                                break;
                            case "public":
                                interfaces.public[tmp2[2].trim()] = tmp2[3].trim();
                                break;
                        }
                    }
                } while (tmp2);
            }
            return interfaces;
        }
    }
})();
