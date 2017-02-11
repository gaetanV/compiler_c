/**
 *  run
 *
 * (c) Gaetan Vigneron <gaetan@webworkshops.fr>
 *  V 0.0.17
 *  11/02/2017
 *  
 **/
(function () {
    'use strict'
    const $path = require('path');
    const $fs = require('fs');
    const $deploy = require($path.join(__dirname, 'core', 'deploy', 'deploy.js'));
    const $hook = require($path.join(__dirname, 'hook.js'));
    let deploy = new $deploy($hook.target,$path.join(__dirname, $hook.bootstrap));
    deploy.build($hook);
    deploy.watch();
})();