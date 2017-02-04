module.exports = (function () {
    'use strict'
    const $fs = require('fs');
    const $path = require('path');
    require($path.join(__dirname, '..', 'natif', 'string.js'));

    const $ecma6 = require($path.join(__dirname, 'build', 'ecma6.js'));
    const $ecma5 = require($path.join(__dirname, 'build', 'ecma5.js'));
    const $repertory = new (require($path.join(__dirname, '..', 'files.js')))();

    const PATH = {
        server: $path.join(__dirname, "..", "..", "/"),
        root_dir: $path.join(__dirname, "..", "/"),
    }
    const REGEX = {
        js: "^(.*).js$",
    }

    return class Deploy {
        constructor(target) {
            this.target = target;
            this.str = "";
        }

        static getClassName(filename, restrict) {
            var className = new RegExp(REGEX.js, "g").exec(filename);
            if (!className) {
                throw("ERROR")
            }
            return className[1];
        }
        compile(){
           

            let result = this.str;
            this.str = " ";
            return result;
        }
        namespace(directory, namespace, restrict) {
            directory = directory.replace(/\\/g, "/");
            namespace = !namespace?directory: namespace.replace(/\\/g, "/");
            return new Promise((resolve, reject) => {
                let innerClass;
                $repertory.src($path.join(PATH.server, directory)).then( (e) => {
                    e.map( (file) => {
                        let fn = Deploy.getClassName(file.name);
                        switch (this.target) {
                            case "es6":
                                innerClass = new $ecma6(fn, file.content );
                                break;
                            case "es5":
                                innerClass = new $ecma5(fn, file.content );
                                break;
                            default:
                                throw "error";
                                break;
                        }
                        this.str += innerClass.build(namespace+file.namespace);
                        
                    })
                    resolve( );
                });
            })
           
        }
        
    }

})();