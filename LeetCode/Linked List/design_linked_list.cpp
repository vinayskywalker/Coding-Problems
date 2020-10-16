#include <bits/stdc++.h>
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
node* head;
int len;
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=NULL;
        len=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=len){
            return -1;
        }
        node* tmp=head;
        for(int i=0;i<index;i++){
            if(tmp->next==NULL){
                return -1;
            }
            tmp=tmp->next;
        }
        return tmp->data;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node* tmp=new node(val);
        tmp->next=head;
        head=tmp;
        len++;
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(head==NULL){
            addAtHead(val);
            return;
        }
        node* tmp=head;
        node* cur;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        cur=new node(val);
        tmp->next=cur;
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>len){
            return;
        }
        else if(index==0){
            addAtHead(val);
        }
        else if(index==len){
            addAtTail(val);
        }
        else{
            node* tmp=head;
            node* prev=NULL;
            for(int i=0;i<index;i++){
                prev=tmp;
                tmp=tmp->next;
            }
            node* res=new node(val);
            prev->next=res;
            res->next=tmp;
            len++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0||index>=len){
            return;
        }
        if(index==0){
            head=head->next;
            len--;
            return;
        }
        node* tmp=head;
        node* prev;
        for(int i=0;i<index;i++){
            prev=tmp;
            tmp=tmp->next;
        }
        prev->next=tmp->next;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */