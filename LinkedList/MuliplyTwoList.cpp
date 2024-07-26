class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long num1 = 0;
        long long num2 = 0;
        long long modulo = 1000000007;
        
        while(first != NULL){
            num1 = num1*10%modulo + first->data;
            first = first->next;
        }
        while(second != NULL){
            num2 = num2*10%modulo + second->data;
            second = second->next;
        }
        
        return (num1*num2)%modulo;
    }
};