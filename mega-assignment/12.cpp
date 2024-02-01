/*Write a menu driven program in C or C++ to perform the following operations on circular linked
list.
(a) insert a node at the beginning of the list.
(b) delete a node at the end of the list.
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
        void ins_beg(int value);
        void del_end();
        void display();
};

void cll::ins_beg(int value){
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
    head = new_node;
    return;
}

void cll::del_end(){
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
    while(temp->next->next != head){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = head;
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
        cout<<"1) Insert element at beginning\n";
        cout<<"2) Delete element from end\n";
        cout<<"3) Display list\n";
        cout<<"0) Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to insert:";
                cin>>value;
                list.ins_beg(value);
                break;
            case 2:
                list.del_end();
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