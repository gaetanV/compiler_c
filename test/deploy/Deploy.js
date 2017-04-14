'use strict'

var chai = require('chai');
var $fs = require('fs');
var expect = chai.expect;
var assert = chai.assert;

var Deploy = require('./../../core/deploy/Deploy');
const $hook = require("./../../hook.js");

describe('DeployArgs', function () {

    assert.isFunction(Deploy);

    expect(function () {
        new Deploy()
    }).to.throw('1');

    expect(function () {
        new Deploy(1)
    }).to.throw("1 type");

    expect(function () {
        new Deploy("a")
    }).to.throw('2');

    expect(function () {
        new Deploy("a", 2)
    }).to.throw('2 type');
});

describe('DeployCoherent', function () {
    expect(function () {
        new Deploy("es5", __dirname + "/test/")
    }).to.throw('path is not found');

    expect(function () {
        new Deploy("es5", __dirname + "./bootstrap.js")
    }).to.throw('path is not found');

    expect(function () {
        new Deploy("es8", __dirname + "/bootstrap.js")
    }).to.throw("error type es8 is not in charge");

    assert.isObject(new Deploy("es5", __dirname + "/bootstrap.js"));

});

describe('Deploy', function () {
    var a = new Deploy("es5", __dirname + "/../../trash/bootstrap.js");
    a.build(__dirname + "/../../", $hook).then(() => {
        assert.isTrue($fs.existsSync(__dirname + "/../../trash/bootstrap.js"));
    });
});