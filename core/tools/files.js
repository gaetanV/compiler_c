'use strict'
module.exports = (function () {
    const $fs = require('fs');

    return class {
        constructor() { }
        src(path, restrict) {
            let parseNamespace = (directory, namespace) => {
                var result = [];
                directory = directory.replace(/\\/g, "/");
                const repertory_path = directory ; 
                return new Promise((resolve, reject) => {
                    $fs.readdir(repertory_path, function (err, files) {
                        if (!files) {
                            resolve([]);
                        }
                        let tasks = files.length - 1;
                        function* thread() {
                            var index = 0;
                            while (index < tasks) {
                                yield index++;
                            }
                        }
                        let iterator = thread();
                        files.forEach(function (file) {
                            var path_file = repertory_path + file;
                            if (!$fs.lstatSync(path_file).isDirectory()) {
                                result.push({namespace: namespace, name: file, content: $fs.readFileSync(path_file, 'utf8')});
                                iterator.next().done === true && (resolve(result));
                            } else {
                                parseNamespace(directory + file + "/", namespace + file).then((valeur) => {
                                    result = result.concat(valeur);
                                    iterator.next().done === true && (resolve(result));
                                })
                            }
                        })
                         

                    })
                });
            }
            return new Promise((resolve, reject) => {
                parseNamespace(path, "").then(function (result) {
                    resolve(result);
                })
            })
        }
    }






})();
