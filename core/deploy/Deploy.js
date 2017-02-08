module.exports = (function () {
    'use strict'
    const $watch = require('node-watch');
    const $path = require('path');
    const $fs = require('fs');
    require($path.join(__dirname, '..', 'natif', 'string.js'));

    const $ecma6 = require($path.join(__dirname, 'class', 'ecma6.js'));
    const $ecma5 = require($path.join(__dirname, 'class', 'ecma5.js'));
    const $repertory = new (require($path.join(__dirname, '..', 'files.js')))();
    const $kernel = require($path.join(__dirname, 'kernel', 'kernel.js'));

    const PATH = {
        server: $path.join(__dirname, "..", "..", "/"),
        root_dir: $path.join(__dirname, "..", "/"),
    }
    const REGEX = {
        js: "^(.*).js$",
    }

    return class Deploy {
        constructor(target, bootstrap) {
            this.bootstrap = bootstrap;
            this.target = target;
            this.str = "";
            this.cycle = [];
        }

        static getClassName(filename, restrict) {
            var className = new RegExp(REGEX.js, "g").exec(filename);
            if (!className) {
                throw("ERROR")
            }
            return className[1];
        }

        autoload(container) {
            let directory = container.src, namespace=container.namespace, restrict=container.restrict;
            directory = directory.replace(/\\/g, "/");
            namespace = !namespace ? directory : namespace.replace(/\\/g, "/");
            return new Promise((resolve, reject) => {
                let innerClass;
                $repertory.src($path.join(PATH.server, directory)).then((e) => {
                    e.map((file) => {
                        let fn = Deploy.getClassName(file.name);
                        switch (this.target) {
                            case "es6":
                                innerClass = new $ecma6(fn, file.content);
                                break;
                            case "es5":
                                innerClass = new $ecma5(fn, file.content);
                                break;
                            default:
                                throw "error";
                                break;
                        }
                        this.str += innerClass.build(namespace + file.namespace);
                    })
                    resolve( );
                });
            })

        }
        build(mapping) {
            let kernel = new $kernel(mapping);
            let cycle = [];
            for (var i in kernel.contenairs) {
                cycle.push(kernel.contenairs[i]);
            }
            this.cycle = cycle;         
            kernel.bootstrap().then((value)=>{
        
                this.str = value;
                this.compile().then(()=>{
                       this.write();
                })
            });
        }
        
        compile() {
            function* thread() {
                var index = 0;
                while (index < this.cycle.length -1) {
                    yield index++;
                }
            }
            let iterator = thread();
            return new Promise((resolve, reject) => {
                for (var index in this.cycle) {
                   this.autoload(this.cycle[index]).then((value) => {               
                        iterator.next().done == 1 && (resolve());
                    })
                }
            });
        }

        write() {
            $fs.writeFile($path.join(this.bootstrap), this.str, function (error) {
                if (error) {
                    console.error("write error:  " + error.message);
                } else {
                    console.log("completed");
                }
            })
            this.src = "";
        }

        watch() {
            for (var i in this.cycle) {
                var watcher = $watch('./' + this.cycle[i].src);
                watcher.on('change', (file) => {
                    this.compile();
                });
            }
        }

    }

})();