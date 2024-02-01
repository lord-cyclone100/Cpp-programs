/*Write a menu driven program in C or C++ to perform the following operations on circular linked
list.
(a) insert a node at the end of the list.
(b) deletet a node from the beginning of the list.
(c) display the whole list.*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

class cll{
    private:
        node* head;
    public:
        cll(){
            head = NULL;
        }
        void ins_end(int value);
        void del_beg();
        void display();
};

void cll::ins_end(int value){
    node* new_node = new node;
    new_node->data = value;
    if(head == NULL){
        head = new_node;
        new_node->next = head;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    return;
}

void cll::del_beg(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = head->next;
    delete head;
    head = temp->next;
    return;
}

void cll::display(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    while(temp != head);
    return;
}

int main(){

    cll list;
    int choice,value;

    do{
        cout<<"\nMenu\n";
        cout<<"1) Insert element at end\n";
        cout<<"2) Delete element from beginning\n";
        cout<<"3) Display list\n";
        cout<<"0) Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to insert:";
                cin>>value;
                list.ins_end(value);
                break;
            case 2:
                list.del_beg();
                break;
            case 3:
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