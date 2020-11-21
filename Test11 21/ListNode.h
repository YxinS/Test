#include<stdio.h>
#include<stdlib.h>
// 1、无头+单向+非循环链表增删查改实现
typedef int Type;
typedef struct SListNode
{
    Type data;
    struct SListNode* next; 
}Node;

int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}

Node* sortList(Node* head){
    if(head == NULL)return NULL;
    int len = 0;
    Node* cur = head;
    while(cur){
        len++;
        cur = cur->next;
    }
    int* arr = (int*)malloc(sizeof(int)*len);
    cur = head;
    for(int i =0; i< len;i++){
        arr[i] = cur->data;
        cur = cur->next;
    }
    qsort(arr,len,sizeof(int),cmp);
    cur = head;
    for(int i = 0;i<len;i++){
        cur->data = arr[i];
        cur=cur->next;
    }
    return head;
}


// 动态申请一个节点
Node* BuySListNode(Type x);
// 单链表打印
void SListPrint(Node* plist);
// 单链表尾插
void SListPushBack(Node** pplist, Type x);
// 单链表的头插
void SListPushFront(Node** pplist, Type x);
// 单链表的尾删
void SListPopBack(Node** pplist);
// 单链表头删
void SListPopFront(Node** pplist);
// 单链表查找
Node* SListFind(Node* plist, Type x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(Node* pos, Type x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(Node* pos);

// 动态申请一个节点
Node* BuySListNode(Type x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}
//从头到尾打印链表
void SListPrint(Node* plist){
    Node* cur = plist;
    while(cur){
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}
//从头到尾打印链表
void SListPrinttou(Node* plist){
        if(plist == NULL){
            return;//空链表
        }
        printf("%d\n",plist ->data);
        SListPrinttou(plist -> next);
}
//从尾到头打印链表
void SListPrintwei(Node* plist){
        if(plist == NULL){
            return;//空链表
        }
        
        SListPrintwei(plist -> next);
        printf("%d\n",plist ->data);
        
}
// 单链表尾插
void SListPushBack(Node** pplist, Type x){
    Node* newList = BuySListNode(x);
    if(*pplist == NULL){
        *pplist = newList;
    }
    else{
        Node* tail = *pplist;
        while(tail->next){
            tail = tail->next;
    }
    tail->next = newList;
    }
}
// 单链表的头插
void SListPushFront(Node** pplist, Type x){
    Node* newList = BuySListNode(x);
    if(*pplist == NULL){
        *pplist = newList;
    }
    else{
        newList->next = *pplist;
        *pplist = newList;
    }

}

// 单链表的尾删
void SListPopBack(Node** pplist){
    //0
    //1
    //多个
    if(*pplist == NULL){
        return;
    }
    else if((*pplist)->next == NULL){
            free(*pplist);
            *pplist = NULL;
    }
    else{
        Node* pre = NULL;
        Node* tail = *pplist;
        while(tail->next){
            pre = tail;
            tail = tail->next;
        }
        free(tail); 
        pre->next =NULL; 
    
    }
    
    

}
// 单链表头删
void SListPopFront(Node** pplist){
    if(*pplist == NULL){
        return;
    }
    else if((*pplist)->next == NULL){
            free(*pplist);
            *pplist = NULL;
    }
    else{
            Node* pre = (*pplist)->next;
            free(*pplist);
            *pplist = pre;
    
    }



}

// 单链表查找
Node* SListFind(Node* plist, Type x){
    if(plist == NULL)return NULL;
    Node* cur = plist;
    while(cur){
        if(cur->data == x){
            return cur;
        }
        else{
            cur = cur->next;
        }
    }
    return NULL;

}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(Node* pos, Type x){
    Node* newlist = BuySListNode(x);
    newlist ->next = pos->next;
    pos->next = newlist;

    // Node* newlist = BuySListNode(x);
    // Node* next = pos->next;
    // pos->next = newlist;
    // newlist->next = next;

}
//删除一个无头单链表的非尾节点（不能遍历）
void ListPop(Node** pplist, Node* pos){
    if(*pplist == NULL){
        return;
    }
    else{
        Node* cur = pos->next;
        pos->data = pos->next->data;
        pos->next = pos->next->next;
        free(cur);
        cur->next = NULL;
    }
}

void ListPop1(Node* pos){
        if(pos == NULL)return;
        Node* cur = pos->next;
        pos->data = pos->next->data;
        pos->next = pos->next->next;
        free(cur);
        cur->next = NULL;
}


// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(Node* pos){
    if(pos == NULL)return;
    Node* next = pos->next;
    if(next){
        pos->next = next->next;
        free(next);
        next->next = NULL;
    }


}


