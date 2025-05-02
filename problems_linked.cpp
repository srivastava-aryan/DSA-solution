#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* reverseLinked(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        Node* front  = temp->next;

        temp->next=prev;

        prev= temp;
        temp = front;
    }
    return prev;
}

Node* addTwoNumbers(Node* l1, Node* l2){    //to add two corresponding linked lists
    Node* dummyhead = new Node(-1);        //dummyhead is used to point the head of the linked list representing the sum of two linked lists
    Node* curr = dummyhead;
    Node* t1 = l1;
    Node* t2 = l2;
    int carry = 0;
    while(t1!=NULL || t2!=NULL){
        int sum = carry;
        if(t1)sum+=t1->data;
        if(t2)sum+=t2->data;
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next=newNode;
        curr = curr->next;

        if(t1)t1=t1->next;
        if(t2)t2=t2->next;
    }
    if(carry){              //if there is any carry left then create a new node with the carry value        
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyhead->next;
}

Node* addTwoNumbersEnd(Node* l1, Node* l2){
    l1 = reverseLinked(l1);
    l2 = reverseLinked(l2);
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    Node* t1 = l1;
    Node* t2 = l2;
    int carry= 0;
    while(t1!=NULL||t2!=NULL){
        int sum = carry;
        if(t1)sum+=t1->data;
        if(t2)sum+=t2->data;
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr= curr->next;

        if(t1)t1 = t1->next;
        if(t2)t2 = t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}
int LengthofLL(Node* head){     //////////to count no. of nodes
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

Node* rotateRight(Node* head, int k) {  // to rotate a linked-list k times
    if(head==NULL||head->next==NULL)return head;
    int cnt = LengthofLL(head);
    int r = k%cnt;
    while(r){
        Node* temp = head->next;
        Node* prev = head;
        while(temp!=NULL){
            if(temp->next==NULL){
                temp->next=head;
                head=temp;
                prev->next=NULL;
                break;
            }
            temp=temp->next;
            prev=prev->next;
        }
        r--;
    }
    return head;
    
}
