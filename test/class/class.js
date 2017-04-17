'use strict'

var chai = require('chai');

var expect = chai.expect;
var assert = chai.assert;

var $class = require('./../../core/class/class.js');
var $ecma6 = require('./../../core/class/lang/ecma6.js');

describe('Class.getImport (static)', () => {

    var file = `
        import { test } from /Bundle/Superbe; 
        import a from '/Bundle/ert  ';
        import {fro} from "/Bundle/Superbe   "; 
        import {a} from "/Bundle/SuperbeA   "; 
    `;

    var A = $class.getImport(file);

    it('Deploy.getImport is Correct Array', () => {
        assert.equal(A.length, 3);
    });

    it('Deploy.getImport is Correct Object', () => {
        assert.equal(A[0].name, "test");
        assert.equal(A[0].space, "/Bundle/Superbe");
        assert.equal(A[1].name, "fro");
        assert.equal(A[1].space, "/Bundle/Superbe");
        assert.equal(A[2].space, "/Bundle/SuperbeA");
    });


});

describe('Class.reflect ', () => {

    var file = `
        export class inject {
            constructor(String value,int integer) {}
            public p1(){}
            public p2(){}
            static s1(){}
            static s2(){}
            private superbe(a,v){}
        }
    `;
    var A = new $ecma6("inject", file);
    
    it('Class.reflect private', () => {
        assert.equal(A.reflect.private.length, 1);
        assert.equal(A.reflect.private[0].args.length, 2);
    });

    it('Class.reflect static', () => {
        assert.equal(A.reflect.static.length, 2);    
    });

    it('Class.reflect public', () => {
        assert.equal(A.reflect.public.length, 2);    
    });


    it('Class.reflect constructor', () => {
        assert.equal(A.reflect.constructor.args.value, "String");
        assert.equal(A.reflect.constructor.args.integer, "int");
    });

});



/**
 TODO:
 
 Limit header import
 
 */