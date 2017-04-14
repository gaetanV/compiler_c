'use strict'

var chai = require('chai');

var $fs = require('fs');
var expect = chai.expect;
var assert = chai.assert;

var Deploy = require('./../../core/deploy/Deploy');
const $hook = require("./../../hook.js");

describe('Deploy.build  Args',  ()  =>{
    it('Deploy.write function', () => {
        assert.isFunction(Deploy);
    });
    it('Deploy.write types', () => {
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

});

describe('Deploy.build Coherent', () => {
    it('Deploy.write type', () => {
        expect(function () {
            new Deploy("es5", __dirname + "/test/")
        }).to.throw('path is not found');

        expect(function () {
            new Deploy("es5", __dirname + "./bootstrap.js")
        }).to.throw('path is not found');

        expect(function () {
            new Deploy("es8", __dirname + "/bootstrap.js")
        }).to.throw("error type es8 is not in charge");

    });
    it('Deploy.write is object', () => {
        assert.isObject(new Deploy("es5", __dirname + "/bootstrap.js"));
    });

});

describe('Deploy.write', () => {
    it('Deploy.write file', (done) => {
        var A = new Deploy("es5", __dirname + "/../../trash/bootstrap2.js");
        A.write().then(() => {
            assert.isTrue($fs.existsSync(__dirname + "/../../trash/bootstrap2.js"));
            assert.equal($fs.readFileSync(__dirname + "/../../trash/bootstrap2.js", 'utf8'), "");
            done();
        });
    });
});


describe('Deploy.getClassName(static)',  ()=> {

    it('Deploy.getClassName type', () => {
        expect(function () {
            Deploy.getClassName("a.js", "jasmin");
        }).to.throw("error type jasmin is not in charge");

        expect(function () {
            Deploy.getClassName("a.java", "js");
        }).to.throw("error type js and file a.java not match");
    });

    it('Deploy.getClassName match', () => {
        assert.equal(Deploy.getClassName("a.go", "go"), "a");
        assert.equal(Deploy.getClassName("b.js", "js"), "b");
    });
});


describe('Deploy.build cycle complet', () => {
    it('Deploy.build cycle complet', (done) => {
        var A = new Deploy("es5", __dirname + "/../../trash/bootstrap.js");
       
        A.build(__dirname + "/../../", $hook).then(() => {
            assert.isTrue($fs.existsSync(__dirname + "/../../trash/bootstrap.js"));
            done();
        });
    });

});


/**
 
TODO:

describe('Deploy.build compile (injection error)', function () {
    it('Deploy.build compile injection', (done) => {
        var A = new Deploy("es5", __dirname + "/../../trash/bootstrap.js");
        A.cycle = ["error injection", "error injection2"];
        A.compile().catch((err) => {
            console.log(err);
        })
    });
});

 */