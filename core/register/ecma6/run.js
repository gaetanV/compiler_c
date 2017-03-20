(function () {
    'use strict'
    
    const $watch = require('node-watch');
    const $fs = require('fs');
    const $repertory = new (require("./../../tools/files.js"))();

    var watcher = $watch('./src');
    watcher.on('change', function (file) {
        compile();
    });
    
    function buildAutoload() {
        return new Promise((resolve, reject) => {
            $repertory.src("./src/").then((e) => {
          
                let src = "module.exports = (function () {\n";
                src += "'use strict'\n";
                e.map((file) => {
                    src += file.content.trim();
                    src += "\n";
                })
                src += "return new Register()";
                src += "\n" + "})();\n";

                resolve(src);
            });
        });
    }
    
    function compile() {
        buildAutoload().then((a) => {
            $fs.writeFile("./register.js", a, function (error) {
                if (error) {
                    console.error("write error:  " + error.message);
                } else {
                    console.log("completed");
                }
            });
        });
    }
    compile();
})();