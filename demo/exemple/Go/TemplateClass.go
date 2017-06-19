interface TemplateClass {
    public  rEnd: <%= type %>;
    private ram: []int;
}

export class TemplateClass {

        constructor (ramLength int){
             this.rEnd     = ramLength
             this.ram      = make([]int ,ramLength)
        }
        public join (a string) ( <%= type %> ){ 
            <% if (strategy) { %>
                this.rEnd ++ 
            <% } %>
            return  this.rEnd
        }
        private test(a string) (string){
            return "<%= type %>"
        }
}