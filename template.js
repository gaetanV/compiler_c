'use strict'

const $build = require("./core/class/Build.js");
var build = new $build("go");

build.template("./exemple/Go/", "./app/assembly.go", "TemplateClass.go", {
    type: "string",
    strategy: true
}, ["join"]);
