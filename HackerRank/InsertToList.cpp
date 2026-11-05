// SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
//     SinglyLinkedListNode* Node = new SinglyLinkedListNode(data);
//     if(llist == nullptr){
//         llist = Node;
//         return llist;
//     }
//     SinglyLinkedListNode* current = llist;
//     while(current && position > 1){
//         current = current->next;
//         position--;
//     }
//     Node->next = current->next;
//     current->next = Node;
//     return llist;
// }