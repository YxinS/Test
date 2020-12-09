#include<iostream>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ret = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode*head = nullptr;
        ListNode*tail = nullptr;
        while(cur1 && cur2){
            int sum = cur1->val + cur2->val +ret;
            if(!head){
                head = tail = new ListNode(sum%10);
            }
            else{
                tail->next = new ListNode(sum%10);
                tail = tail->next;
            }
            ret = sum/10;


            cur2 = cur2->next;
            cur1=cur1->next;
        }
        while(cur1){
            if(ret){
                tail->next = new ListNode((cur1->val+ret)%10);
                tail = tail->next;
                ret = (cur1->val+ret)/10;
            }
            else{
                tail->next = new ListNode(cur1->val);
                tail = tail->next;
            }
            
            cur1=cur1->next;
        }
        while(cur2){
            if(ret){
                tail->next = new ListNode((cur2->val+ret)%10);
                tail = tail->next;
                ret = (cur2->val+ret)/10;
            }
            else{
                tail->next = new ListNode(cur2->val);
                tail = tail->next;
            }
            
            cur2=cur2->next;
        }
        if(ret){
            tail->next = new ListNode(ret);
            tail = tail->next;
        }
        return head;

    }
};



int main(){
    ListNode* cur = new ListNode(2);
    cur->next = new ListNode(4);
    cur->next->next=new ListNode(3);
    ListNode* cur2 = new ListNode(5);
    cur2->next = new ListNode(6);
    cur2->next->next = new ListNode(4);
    ListNode*pre =  Solution().addTwoNumbers(cur,cur2);
    while(pre){
        cout << pre->val <<endl;
        pre=pre->next;
    }


    return 0;
}