
'use strict'
const $path = require('path');
const $deploy = require($path.join(__dirname, 'core', 'deploy', 'deploy.js'));
var deploy = new $deploy("go", $path.join(__dirname, "./app/object.go"));
deploy.class("./exemple/Go/", "ArrayClass.go");
