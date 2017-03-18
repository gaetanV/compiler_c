(function () {
    'use strict'
    const $path   = require('path');
    const $deploy = require($path.join(__dirname, 'core', 'deploy', 'deploy.js'));
    const $hook   = require($path.join(__dirname, 'hook.js'));
    var deploy = new $deploy("es6",$path.join(__dirname, "./app/bootstrap.js"));
    deploy.build($hook);
    deploy.watch();
})();