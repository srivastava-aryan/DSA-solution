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
