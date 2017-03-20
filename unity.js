'use strict'

const $build = require("./core/class/Build.js");
var build = new $build("go");

build.class("./exemple/Go/","./app/object.go", "ArrayClass.go");