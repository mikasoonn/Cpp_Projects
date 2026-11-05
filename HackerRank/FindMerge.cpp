// int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
//     SinglyLinkedListNode* current = head1;
//     int size1 = 0;
//     while(current){
//         size1++;
//         current = current->next;
//     }
//     current = head2;
//     int size2 = 0;
//     while(current){
//         size2++;
//         current = current->next;
//     }
//     int diff;
//     SinglyLinkedListNode* current1 = head1;
//     SinglyLinkedListNode* current2 = head2;
//     if(size1 > size2){
//         diff = size1 - size2;
//         while(diff){
//             current1 = current1->next;
//             diff--;
//         }
//     }else if(size2 > size1){
//         diff = size2 - size1;
//         while(diff){
//             diff--;
//             current2 = current2->next;
//         }
//     }
//     while(current1 != current2){
//         current1 = current1->next;
//         current2 = current2->next;
//     }
//     return current1->data;
    
    
// }