module.exports = (function () {
    'use strict'

    const $watch        = require('node-watch');
    const $fs           = require('fs');
    const $go           = require('./lang/go.js');
    const $ecma6        = require('./lang/ecma6.js');

    
    require('./../tools/string.js');

    const PATH = {
        server  : __dirname + "/../../",
        root_dir: __dirname + "/../",
    }
    
    const REGEX = {
        js: "^(.*).js$",
        go: "^(.*).go",
    }

    return class Deploy {
        constructor(target) {
            this.target = target;
        }

        static getClassName(filename, type) {
            var className = new RegExp(REGEX[type], "g").exec(filename);
            if (!className) {
                throw("ERROR")
            }
            return className[1];
        }

        template(path, name, output, scope, method) {
            var innerClass;
            var path_file =  PATH.server + path + name;
            var file = $fs.readFileSync(path_file, 'utf8')
            switch (this.target) {
                case "go":
                    innerClass = new $go(Deploy.getClassName(name, "go"), file);
                    break;
                default:
                    throw "error";
                    break;
            }
            this.write(innerClass.buildTemplate(scope, method),output);
        }
        
        class(path, name, output) {
            var innerClass;
            var path_file = PATH.server + path + name;
            var file = $fs.readFileSync(path_file, 'utf8')
            switch (this.target) {
                case "es6":
                    innerClass = new $ecma6(Deploy.getClassName(name, "js"), file);
                    break;
                case "go":
                    innerClass = new $go(Deploy.getClassName(name, "go"), file);
                    break;
                default:
                    throw "error";
                    break;
            }
            this.write(innerClass.build(), output);
        }
        
        watch(collection) {  
        }

        write(str, output) {
            $fs.writeFile(output, str, function (error) {
                if (error) {
                    console.log("write error:  " + error.message);
                } else {
                    console.log("completed");
                }
            })
            this.str = "";
        }

        

    }

})();