(function () {
    'use strict'
    const $fs = require('fs');
    const $path = require('path');
    require($path.join(__dirname, 'natif.js'));
    const $ecma6 = require($path.join(__dirname, 'build', 'ecma6.js'));
    const $ecma5 = require($path.join(__dirname, 'build', 'ecma5.js'));

    const PATH = {
        server: $path.join(__dirname, "..", "/"),
        root_dir: $path.join(__dirname, "/"),
    }
    const REGEX = {
        js: "^(.*).js$",
    }

    class Deploy {
        constructor(target) {
            this.target = target;
            this.str = "";
        }

        static getClassName(filename, restrict) {
            if (restrict) {
                let classNameRestrict = restrict.exec(filename);
                if (!classNameRestrict) {
                    throw("ERROR RESTRICT")
                }
            }
            var className = new RegExp(REGEX.js, "g").exec(filename);
            if (!className) {
                throw("ERROR")
            }
            return className[1];
        }

        parseNamespace(directory, namespace, restrict) {
            directory = directory.replace(/\\/g, "/");
            if (!namespace) {
                namespace = directory
            } else {
                namespace = namespace.replace(/\\/g, "/")
            }
            const repertory_path = $path.join(PATH.server, directory);
            let vm = this;
            return new Promise((resolve, reject) => {
                $fs.readdir(repertory_path, function (err, files) {
                    let tasks = files.length - 1;
                    function* thread() {
                        var index = 0;
                        while (index < tasks) {
                            yield index++;
                        }
                    }
                    let iterator = thread(), innerClass;
                    files.forEach(function (file) {
                        let path_file = $path.join(repertory_path, file);
                        if (!$fs.lstatSync(path_file).isDirectory()) {
                            let fn = Deploy.getClassName(file, vm.restrict);
                            switch (vm.target) {
                                case "es6":
                                    innerClass = new $ecma6(fn, $fs.readFileSync(path_file, 'utf8'));
                                    break;
                                case "es5":
                                    innerClass = new $ecma5(fn, $fs.readFileSync(path_file, 'utf8'));
                                    break;
                                default:
                                    throw "error";
                                    break;
                            }
                            vm.str += innerClass.build(namespace);
                            iterator.next().done == 1 && (resolve( ));
                        } else {
                            tasks++;
                            parseNamespace($path.join(directory, file, "/"), $path.join(namespace, file, "/"), restrict).then(
                                    (valeur) => {iterator.next().done == 1 && (resolve( ));}
                            )
                        }
                    })
                })
            })
        }
    }
    module.exports = Deploy;
})();