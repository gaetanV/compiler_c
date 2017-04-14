'use strict'

const $deploy = require("./core/deploy/deploy.js");
const $hook   = require("./hook.js");

var deploy = new $deploy("es5", __dirname + "/app/bootstrap.js");
deploy.build( __dirname,$hook);
deploy.watch();