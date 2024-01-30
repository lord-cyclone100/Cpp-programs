/*Write a menu driven program in C or C++ to perform the following operations on single linked list.
 (a) insert a node at the beginning of the list.
 (b) insert a node at the end of the list.
 (c) deletet a node from the beginning of the list.
 (d) delete a node at the end of the list.
 (e) display the whole list*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

class sll{
    public:
        node* head;
        sll(){
            head = NULL;
        }
        void ins_beg(int value);
        void ins_end(int value);
        void del_beg();
        void del_end();
        void display();
};

void sll::ins_beg(int value){
    node* new_node = new node;
    new_node->data = value;
    if(head == NULL){
        new_node->next = NULL;
        head = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
    return;
}

void sll::ins_end(int value){
    node* new_node = new node;
    new_node->data = value;
    if(head == NULL){
        new_node->next = NULL;
        head = new_node;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    new_node->next = NULL;
    temp->next = new_node;
    return;
}

void sll::del_beg(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    return;
}

void sll::del_end(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next->next;
    temp->next = NULL;
    return;
}

void sll::display(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return;
}

int main(){
    sll list;
    int choice,value;
    do{
        cout<<"\nMenu\n";
        cout<<"1.)Insert element at beginning\n";
        cout<<"2.)Insert element at end\n";
        cout<<"3.)Delete element from beginning\n";
        cout<<"4.)Delete element from end\n";
        cout<<"5.)Display\n";
        cout<<"0.)Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element to add at beginning:";
                cin>>value;
                list.ins_beg(value);
                break;
            case 2:
                cout<<"Enter element to add at end:";
                cin>>value;
                list.ins_end(value);
                break;
            case 3:
                list.del_beg();
                break;
            case 4:
                list.del_end();
                break;
            case 5:
                list.display();
                break;
            case 0:
                cout<<"Exiting...";
                break;
            default:
                cout<<"Invalid choice";
                break;
        }
    }
    while(choice != 0);
    return 0;
}