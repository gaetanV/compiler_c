class Space {
    constructor(owner) {
        this.children = [];
        this.Class = [];
    }
    class(name, fn, inject) {
        if (!this.Class[name]) {
            this.Class[name] = new Class(fn, inject);
        } else {
            console.log("ERROR CLASS IS ALREADY DEFININED");
        }
    }
}