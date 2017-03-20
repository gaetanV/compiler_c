module.exports = (function () {
    'use strict'

    const $watch        = require('node-watch');
    const $fs           = require('fs');
    const $go           = require('./../class/lang/go.js');
    const $ecma6        = require('./../class/lang/ecma6.js');
    const $services     = require('./bootstrap/services/lang/ecma6.js');
    const $containers   = require('./bootstrap/containers/lang/ecma6.js');
    const $deamons      = require('./bootstrap/deamons/lang/ecma6.js');
    const $repertory    = new (require('./../tools/files.js'))();
    
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
        constructor(target, bootstrap) {
            this.bootstrap = bootstrap;
            this.target = target;
            this.str = "";
            this.cycle = [];
        }

        static getClassName(filename, type) {
            var className = new RegExp(REGEX[type], "g").exec(filename);
            if (!className) {
                throw("ERROR")
            }
            return className[1];
        }

        autoload(container) {
            let directory = container.src, namespace = container.name, restrict = container.restrict;
            namespace = "/" + namespace.replace(/\\/g, "_").replace(/\\\\/g, "_").trim() + "/";
            return new Promise((resolve, reject) => {
                let innerClass;
                $repertory.src(PATH.server + directory).then((e) => {
                    e.map((file) => {
                        switch (this.target) {
                            case "es6":
                                var fn = Deploy.getClassName(file.name, "js");
                                innerClass = new $ecma6(fn, file.content);
                                break;
                            default:
                                throw "error";
                                break;
                        }
                        this.str += `register('${namespace}').class('${innerClass.funcName}', class {\n${innerClass.inner()}}\n,${JSON.stringify(innerClass.reflect.constructor.args)});\n`;
                    })

                    resolve( );
                });
            })

        }
        build(mapping) {

            var containers = new $containers(mapping);
            var services   = new $services(mapping);
            var deamons    = new $deamons(mapping);
            var cycle = [];

            for (var i in containers.container) {
                cycle.push(containers.container[i]);
            }
            for (var i in services.service) {
                cycle.push(services.service[i]);
            }
            for (var i in deamons.deamon) {
                cycle.push(deamons.deamon[i]);
            }

            this.cycle = cycle;

            containers.build().then((value) => {
                this.str = value;
                this.compile().then(() => {
                    this.write();
                })
            });
        }
 
        compile() {
            let limit = this.cycle.length;
            function* thread() {
                var index = 0;
                while (index < limit - 1) {
                    yield index++;
                }
            }
            let iterator = thread();
            return new Promise((resolve, reject) => {
                for (var index in this.cycle) {
                    this.autoload(this.cycle[index]).then(() => {
                        iterator.next().done === true && (resolve());
                    })
                }
            });
        }

        write() {
            $fs.writeFile(this.bootstrap, this.str, function (error) {
                if (error) {
                    console.log("write error:  " + error.message);
                } else {
                    console.log("completed");
                }
            })
            this.str = "";
        }

        watch() {
            for (var i in this.cycle) {
                var watcher = $watch('./' + this.cycle[i].src);
                watcher.on('change', () => {
                    this.compile();
                });
            }
        }

    }

})();