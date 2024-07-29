void zigZagList(Node* head){
    bool flag = true;
 
    // Traverse linked list starting from head.
    Node* current = head;
    while (current->next != NULL) {
        if (flag){
            if (current->data > current->next->data)
                swap(current->data, current->next->data);
        }
        else{
            if (current->data < current->next->data)
            swap(current->data, current->next->data);
        }
 
        current = current->next;
        flag = !flag;
    }
}