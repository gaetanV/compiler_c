'use strict'

const $build = require("./core/class/Build.js");
var build = new $build("go");

build.class("./exemple/Go/", "ArrayClass.go", "./app/object.go");