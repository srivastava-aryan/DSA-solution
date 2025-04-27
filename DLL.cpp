#include<bits/stdc++.h>
using namespace std;
class Node{                     //a multi-constructor class
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){          //constructor to initialize the data, next pointer and back pointer
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){                            //constructor to initialize the data only and set next and back pointers to null
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};
Node* convertToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head){        //print function to print the nodes (values) of the linked list
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}
Node* deleteHead(Node* head){           //to delete the head of the DLL
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* prev = head;           //prev is taken to point the head aas it will get detached from dll
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;
    delete prev;                //after that prev will be deleted from the memory
    return head;
}
Node* deleteTail(Node* head){               //to delete the tail of the DLL
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;          // to cutoff next from tail
    tail->back = nullptr;           //to cutoff back from tail so that tail could be reomoved
    delete tail;
    return head;
}
Node* removeKthElement(Node* head, int k){      //to remove kth Element 
    if(head==NULL){                        //edge case for empty DLL
        return NULL;
    }
    int cnt= 0;
    Node* knode = head;
    while(knode != NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        knode = knode->next;
    }
    Node* prev = knode->back;
    Node* front = knode->next;
    if(prev==NULL && front == NULL){            //for single node DLL
        return NULL;
    }
    else if(prev==NULL){
        return deleteHead(head);                //if kth node is head node
    }
    else if(front == NULL){
        return deleteTail(head);                //if kth node is tail node
    }
    prev->next = front;                         //skipping knode and connecting its prev node to its front node
    front->back = prev;

    knode->next=nullptr;                        //setting back and next to nullptr 
    knode->back=nullptr;
    delete knode;                               //deleteing kth node
    return head;
}
void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return;
    }
    prev->next=front;
    front->back=prev;

    temp->back=temp->next=nullptr;
    free(temp);
    return;
}
Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}
Node* insertBeforeTail(Node* head, int val){
    if(head->next==NULL){                            //if there is a single node
        return insertBeforeHead(head, val);             //head and tail are same here
    }
    Node* tail = head;
    while(tail->next !=NULL){
        tail=tail->next;
    }
    Node* prev = tail->back;                //setting up connections and cutting off the old one
    Node* newNode = new Node(val,tail,prev);
    prev->next=newNode;
    tail->back = newNode;
    return head;
}

Node* reverseDLL(Node* head){                       //to reverse the doubly linked list
    if(head==NULL || head->next==NULL)return head;          //necessary edge condition
    Node* prev = nullptr;                                    
    Node* current = head;
    while(current != NULL){
        prev = current->back;                                 //swapping of links in these three lines
        current->back = current->next;
        current->next = prev;

        current = current->back;                               //to update value of current for completion of while loop    
    }
    return prev->back;
}

Node* reverseLinked(Node* head){
    if(head == NULL || head->next == NULL)return head;
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        Node* front = temp->next;       // Store the next node in // 'front' to preserve the reference

        temp->next = prev;               // Reverse the direction of the current node's 'next' pointer to point to 'prev'
        ///now updatin the variables
        prev = temp;
        temp = front;
    }
    return prev;  //prev will be the new head of the reversed linked list
}

Node* reverseList(Node* head){      //recursive approach to reverse a linked list
    if(head==NULL || head->next==NULL){             //edge case
        return head;
    }
    Node* newHead = reverseList(head->next);            ///recursion : to break big problem into smaller chunks
    Node* front = head->next;
    front->next=head;
    head->next=NULL;
    return newHead;

}

bool detectCycle(Node* head){           //to detect loop in linked list
    Node* fast = head;                     //Tortoise & hare method is used 
    Node* slow = head;                      // two pointers are taken and they will collide at any point if loop is present.
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> arr = {32,3,4,5,6,7};
    Node* head = convertToDLL(arr);
    head = reverseDLL(head);
    print(head);
    return 0;
}
