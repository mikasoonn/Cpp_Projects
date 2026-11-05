// DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
//     if(llist == nullptr || llist -> next == nullptr){
//         return llist;
//     }
//     DoublyLinkedListNode* next = nullptr;
//     DoublyLinkedListNode* prev = nullptr;
//     DoublyLinkedListNode* current = llist;
//     while(current->next){
//         next = current->next;
//         current->next = prev;
//         current->prev = next;
//         prev = current;
//         current = next;
//     }
//     current->next = current->prev;
//     current->prev = nullptr;
//     llist = current;
//     return llist;
    
// }