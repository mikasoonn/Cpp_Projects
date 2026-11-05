// bool has_cycle(Node* head) {
//     // Complete this function
//     // Do not write the main method
//     if(head == nullptr || head->next == nullptr){
//         return false;
//     }
//     Node* fastPtr = head->next;
//     Node* slowPtr = head;
//     while(fastPtr -> next != nullptr && fastPtr->next->next != nullptr ){
//         if(fastPtr == slowPtr){
//             return true;
//         }
//         fastPtr = fastPtr->next->next;
//         slowPtr = slowPtr->next;
//     }
//     return false;
// }