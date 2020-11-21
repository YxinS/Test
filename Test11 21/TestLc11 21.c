#include"ListNode.h"


int main(){
    Node* head = BuySListNode(6);
    SListPushBack(&head,5);
    SListPushBack(&head,4);
    SListPushBack(&head,3);
    SListPushBack(&head,2);
    SListPushBack(&head,1);
    SListPrint(head);  
    sortList(head);
    SListPrint(head);


    return 0;
}