module.exports = (function () {
    'use strict'
    const REGEX = {
        import: "import[^\{]*{([^\}]*)}[^f]*from([^;]*)",
        export: "export[\\s]*class[\\s]*${func}[\\s]*([^\{]*)\{",
        interface: "interface[^\{]*{([^\}]*)}",
        interfaceInner : "[\r\n]*(private[\\s]*|static[\\s]*|public[\\s]*)([^\:]*):([^\;]*);",
        reflect: "(private[\\s]*|static[\\s]*|public[\\s]*|constructor[\\s]*)([^\(]*)\\(([^\)]*)\\)(.*)[\{]{1}",
    }
    return class Class {
        constructor(funcName, file) {
            this.funcName = funcName;
            let match = new RegExp(REGEX.export.apply({func: this.funcName}), "g").exec(file);
           
            if (!match) {
                throw "ERROR " + this.funcName + " CLASS IS NOT CORRECTLY DEFINED"
            }
     
            let inject = Class.getImport(file);
   
            let pointer = match.index + match[0].length;
            
            let end = false;
            var map = [], current = [], d;
            Class.getBracket(file).map(function (a, b) {
                if (a === 1) {
                    current.push(b);
                }
                ;
                if (a === -1) {
                    d = current.pop();
                    if (d > (pointer) && !end) {
                        map[d - (pointer)] = b - (pointer)
                    }
                    ;
                    pointer - 1 === d && (end = b);
                }
            });
            this.interface = Class.getInterface(file);
            this.content = file.slice(pointer, end);
            this.index = map;
            this.reflect = this.getReflect(this.content);
        }
        getReflect(c) {
            let inject = {"public": [], "private": [], "static": [], "constructor": {}}, m = new RegExp(REGEX.reflect, "g"), match, args ,tmp;
            do {
                match = m.exec(c);
                if (match) {
                    args = Class.parseArrayFunc(match[3]);
                    let index = {start: match.index, end: match.index + match[0].length};
                    let type = match[1].trim();              
                    var r = match[4].trim().replace("(","").replace(")","").split(",");
                    let result = {type: type, return: r ,content: this.content.slice(index.end, this.index[index.end - 1]).trim(), index: index, argsText: match[3], name: match[2], args: args};
                    switch (type) {
                        case "constructor":
                            let t ={};
                            args.map(function (a, b) {
                               var  c = a.trim().split(" ");
                               if(c[0]&&c[1]){
                                   t[c[1]]=c[0];
                               }else{
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
            
            return inject
        }

        static parseArrayFunc(txt) {
            return txt.split(",").map(function (arg) {
                return arg.replace(/\/\*.*\*\//, '').trim();
            }).filter(function (arg) {
                return arg;
            });
        }
        static getBracket(file) {
            let  closure = [];
            function getAllIndexes(arr, val, indexMin) {
                let indexes = [], i = -1;
                while ((i = arr.indexOf(val, i + 1)) !== -1) {
                    if (i >= indexMin)
                        indexes.push(i);
                }
                return indexes;
            }
            getAllIndexes(file, "{", 0).map(function (a, b) {
                closure[a] = 1;
            });
            getAllIndexes(file, "}", 0).map(function (a, b) {
                closure[a] = -1;
            });
            return closure;
        }
        static  getImport(file) {
            let inject = [], m = new RegExp(REGEX.import, "g"), tmp;
            do {
                tmp = m.exec(file);
                if (tmp) {
                    inject.push({name: tmp[1], space: tmp[2]});
                }
            } while (tmp);
            return inject
        }
        static  getInterface(file) {
            var interfaces = {private:{},public:{}}, m = new RegExp(REGEX.interface, "g") , inner = new RegExp(REGEX.interfaceInner, "g") ,tmp2;
            var tmp = m.exec(file);
            if (tmp) {
               do {
                   tmp2 = inner.exec(tmp[1]);
                   if(tmp2){
                       switch(tmp2[1].trim()){
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
