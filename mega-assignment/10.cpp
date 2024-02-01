/*Write a menu driven program in C or C++ to implement a queue using single linked list and
perform the following operations.
(a) isEmpty() is to check whether the queue is empty or not.
(b) insert() is to insert an item in the queue.
(c) del() is to delete an item from the queue.
(d) display() is to show the entire queue.*/

#include<iostream>
using namespace std;
#define MAX 5

class node{
    public:
        int data;
        node* next;
};

class sll{
    private:
        node* head;
        int count;
    public:
        sll(){
            head = NULL;
            count = -1;
        }
        void is_empty();
        void insert(int value);
        void del();
        void display();
};

void sll::is_empty(){
    if (head==NULL){
        cout<<"Queue is empty";
        return; 
    }
    cout<<"Queue is not empty";
    return;
}

void sll::insert(int value){
    if(count < MAX -1){
        count++;
        node* new_node = new node;
        new_node->data = value;
        if (head ==NULL){
            head = new_node;
            new_node->next = NULL;
            return;
        }
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
        return;
    }
    else{
        cout<<"Queue overflow";
        return;
    }
    
}

void sll::del(){
    if(head == NULL){
        cout<<"Queue underflow";
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    return;
}

void sll::display(){
    if(head == NULL){
        cout<<"Empty queue";
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
    sll queue;
    int choice,value;
    do{
        cout<<"\nMenu\n";
        cout<<"1.)Is Empty\n";
        cout<<"2.)Insert\n";
        cout<<"3.)Delete\n";
        cout<<"4.)Display\n";
        cout<<"0.)Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                queue.is_empty();
                break;
            case 2:
                cout<<"Enter element to insert:";
                cin>>value;
                queue.insert(value);
                break;
            case 3:
                queue.del();
                break;
            case 4:
                queue.display();
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