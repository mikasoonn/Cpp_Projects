// DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
//     DoublyLinkedListNode* Node = new DoublyLinkedListNode(data);
//     if(llist == nullptr){
//         llist = Node;
//         return llist;
//     }
//     if(llist->data >= data){
//         llist->prev = Node;
//         Node->next = llist;
//         Node->prev = nullptr;
//         llist = Node;
//         return llist;
//     }
//     DoublyLinkedListNode* current = llist;
//     while(current->next && current->next->data < data){
//         current = current->next;
//     }
//     if(current->next){
//         Node->next = current->next;
//         Node->prev = current;
//         current->next->prev = Node;
//         current->next = Node;
//     }else{
//         current->next = Node;
//         Node->prev = current;
//         Node->next = nullptr;
//     }
//     return llist;
// }