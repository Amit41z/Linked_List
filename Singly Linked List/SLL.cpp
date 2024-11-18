#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node* newnode = new Node(val);
    newnode->next=head;
    head=newnode;
}

void insertAtTail(Node* &head, int val){
    Node* newnode = new Node(val);

    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertAtPosition(Node* &head, int val, int pos){
    if(pos==0){
        insertAtHead(head,val);
        return;
    }

    Node* newnode=new Node(val);
    Node* temp=head;
    int curr_pos=0;
    while(curr_pos!=pos-1){
        temp=temp->next;
        curr_pos++;
    }

    newnode->next=temp->next;
    temp->next=newnode;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head=NULL;
    insertAtHead(head,1);
    display(head);
    insertAtHead(head,2);
    display(head);
    insertAtTail(head,3);
    display(head);
    insertAtPosition(head,4,2);
    display(head);

    return 0;
}