'use strict'

const $build = require("./core/class/Build.js");
var build = new $build("go");

build.template("./exemple/Go/", "TemplateClass.go", "./app/assembly.go", {
    type: "string",
    strategy: true
}, ["join"]);
