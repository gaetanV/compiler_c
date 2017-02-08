module.exports = (function () {
    'use strict'
    const $fs = require('fs');
    const $path = require('path');
    const $container = require($path.join(__dirname, 'container.js'));


    return class Kernel {
        constructor(hook) {
            this.hook = hook;
            this.contenairs = [];
            for (var i in hook.contenairs) {
                this.contenairs[i] = new $container(hook.contenairs[i], i);
            }

        }
        bootstrap() {
           let bootstrap = `let key = new Key({ method: "strict", role: "root" });\n`;
            bootstrap += `new bootstrap(key,{\n`;
            function* thread() {
                var index = 0;
                while (index < Object.keys(this.contenairs).length - 1) {
                    yield index++;
                }
            }
            let iterator = thread();
            return new Promise((resolve, reject) => {
                for (var index in this.contenairs) {
                    this.contenairs[index].build().then((value) => {
                        bootstrap += value;
                        if (iterator.next().done == 1) {
                            bootstrap += "};\n";
                            resolve(bootstrap);
                        }
                        
                    })
                }
            });
        }
    }
})();
