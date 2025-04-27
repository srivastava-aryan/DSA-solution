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

// int main(){
//     vector<int> arr = {0,1,2,3,4};
//     Node* y = new Node(arr[2]);
//     cout<<y;
    // cout<<y->data; : gives data value
    //Node y = Node(arr[2],nullptr);
    //cout<<y.data; : gives data value
//}

Node* convertArr2LL(vector<int> &arr){            ////to convert an array to linked list
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);   //mover is used to traverse on nodes one after other
        mover->next = temp;
        mover = temp;    ////then value of mover is changed or incremented to further next value
    }
    return head;
    
}
int main(){
    vector<int> arr = {32,3,4,5,6,7};
    Node* head = convertArr2LL(arr);
    cout<< head->data;
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

int checkIfPresent(Node* head, int val){      //to check if the given value is present or not
    Node* temp = head;                        //temp is used to traverse the linked list
    if(head==NULL)return 0;                  //if head is null then return 0    
    while(temp){
        if(temp->data==val)return 1;
        temp = temp->next;                   //next node is assigned to temp variable

    }
    return 0;
}

Node* removesHead(Node* head){
    if(head==NULL)return head;
    Node* temp = head;
    head=head->next;
    delete temp;        //temp variable is used to point the preev head and to free it from memory
    return head;
}

Node* removesTail(Node* head){
    if(head==NULL||head->next==NULL)return NULL;     //atleast 2 nodes are required to remove the tail node
    Node* temp = head;                          
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next= nullptr;
    return head;

}

Node* removesK(Node* head, int k){  //removes kth elemnt
    if(head==NULL)return head;        //if head is null then return null
    if(k>LengthofLL(head))return head; //if k is greater than length of linked list then return head
    if(k==1){
        Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;  //prev is used to point the next node of the kth node to connect the nodes at the time of remving kth node
            free(temp);
            break;
        }
        prev=temp;
        temp = temp->next;
    }
    return head;
}

Node* insertAtHead(Node* head, int val){  //to insert a node at the head of the linked list
    Node* temp = new Node(val);
    temp->next = head;   //temp is used to point the next node of the head to connect the nodes at the time of inserting a new node at the head
    return temp;
}

Node* insertTail(Node* head, int val){    //to insert a node at the tail of the linked list
    if(head==NULL){
        return new Node(val);               //if head is null then return new node
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode = new Node(val);
    temp->next=newNode;             //temp is used to point the next node of the tail to connect the nodes at the time of inserting a new node at the tail
    return head;
}

Node* insertK(Node* head, int k, int val){  
    if(head==NULL){
        if(k==1){
            return new Node(val);           //if head is null and k is 1 then return new node
        }
        else{
            return head;                   //if head is null and k is not 1 then return head
        }
    }
    if (k==1){
        Node* newhead = new Node(val);   //if k is 1 then return new node
        newhead->next = head;           //newhead is used to point the next node of the head to connect the nodes at the time of inserting a new node at the head
        return newhead;      
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* x = new Node(val);
            x->next = temp->next;  //x is used to point the next node of the kth node to connect the nodes at the time of inserting a new node at the kth position
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertbefore(Node* head, int val,int k){   //insert before any value
    if(head==NULL)return NULL;        //if head is null then return null
    if(head->data==k){
        Node* newnode = new Node(val);  //if head is equal to k then return new node
        newnode->next = head;          //newnode is used to point the next node of the head to connect the nodes at the time of inserting a new node at the head
        return newnode;                //return new node
    }
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data==k){
            Node* newnode = new Node(val);
            newnode->next = temp->next;
            temp->next = newnode;
            break;                                  //newnode is used to point the next node of the head to connect the nodes at the time of inserting a new node at the head
        }
        temp=temp->next;   
    }
    return head;                          
}

Node* startingPoint(Node* head){            //to find the starting point of the loop in a linked list
    if(head==NULL)return NULL;                  //if head is null then return null
    unordered_map<Node*,int> NodeMap;      //unordered map is used to store the address of the node and its value   
    Node* temp = head;
    while(temp!=NULL){
        if(NodeMap.count(temp)!=0){             
            return temp;
        }
        NodeMap[temp]=1;
        temp=temp->next;
    }
    return nullptr;
    
}

int lengthofLoop(Node* slow, Node* fast){       //to find the length of the loop in a linked list
    int cnt =1;
    fast=fast->next;
    while(slow!=fast){              
        cnt++;
        fast=fast->next;
    }                                                   
    return cnt;
}

int findLengthofLoop(Node* head){      //to determine if there is a loop in the linked list and to find the length of the loop
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return lengthofLoop(slow,fast);
        }
    }
    return 0;
}

string isPalindrome(Node* head){  //to check whether a linked list is palindrome or not(BRUTE)
    Node* temp = head;              
    stack<int> st;                      //STACK is used to store the data values and matching
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data!=st.top()){
            return "NO";
        }
        st.pop();
        temp=temp->next;
    }
    return "YES";
}

