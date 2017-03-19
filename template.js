(function () {
    'use strict'
    const $path = require('path');
    const $deploy = require($path.join(__dirname, 'core', 'deploy', 'deploy.js'));
    var deploy = new $deploy("go",$path.join(__dirname, "./app/assembly.go"));
    deploy.template("./exemple/Go/","TemplateClass.go",{
        type:"string",
        strategy: true
    },["join"]);
})();