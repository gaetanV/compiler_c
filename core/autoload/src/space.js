class Space {
    constructor(owner) {
        this.children = [];
        this.owner = owner;
        this.Class = [];
        this.Abstract = [];
        this.Interface = [];
    }
    class(name, fn, inject) {
        if (!this.Class[name]) {
            this.Class[name] = new Class(fn, inject);
        } else {
            console.log("ERROR CLASS IS ALREADY DEFININED");
        }
    }
}