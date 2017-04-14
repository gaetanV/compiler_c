'use strict'

var chai = require('chai');

var $fs = require('fs');
var expect = chai.expect;
var assert = chai.assert;

var $class = require('./../../core/class/class.js');


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

/**
TODO:

Limit header import

*/