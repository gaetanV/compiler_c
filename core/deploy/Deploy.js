module.exports = (function () {
    'use strict'
    const $watch = require('node-watch');
    const $path = require('path');
    const $fs = require('fs');
    require($path.join(__dirname, '..', 'tools', 'string.js'));

    const $go = require($path.join(__dirname, 'class', 'lang', 'go.js'));
    const $ecma6 = require($path.join(__dirname, 'class', 'lang', 'ecma6.js'));
    const $services = require($path.join(__dirname, 'bootstrap', 'services', 'lang', 'ecma6.js'));
    const $containers = require($path.join(__dirname, 'bootstrap', 'containers', 'lang', 'ecma6.js'));
    const $deamons = require($path.join(__dirname, 'bootstrap', 'deamons', 'lang', 'ecma6.js'));

    const $repertory = new (require($path.join(__dirname, '..', 'tools', 'files.js')))();


    const PATH = {
        server: $path.join(__dirname, "..", "..", "/"),
        root_dir: $path.join(__dirname, "..", "/"),
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
                $repertory.src($path.join(PATH.server, directory)).then((e) => {
                    e.map((file) => {
                        switch (this.target) {
                            case "es6":
                                var fn = Deploy.getClassName(file.name, "js");
                                innerClass = new $ecma6(fn, file.content);
                                break;
                            case "go":
                                var fn = Deploy.getClassName(file.name, "go");
                                innerClass = new $go(fn, file.content);
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
            let containers = new $containers(mapping);
            let services = new $services(mapping);
            let deamons = new $deamons(mapping);
            let cycle = [];

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
        template(path, name, scope, method) {
            var innerClass;
            var path_file = $path.join(PATH.server, path, name)
            var file = $fs.readFileSync(path_file, 'utf8')
            switch (this.target) {
                case "go":
                    innerClass = new $go(Deploy.getClassName(name, "go"), file);
                    break;
                default:
                    throw "error";
                    break;
            }
            this.str = innerClass.buildTemplate(scope,method);
            this.write();
        }
        class(path, name) {
            var innerClass;
            var path_file = $path.join(PATH.server, path, name)
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
            this.str = innerClass.build();
            this.write();
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
            this.str = "";
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