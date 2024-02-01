/*Write a menu driven program in C or C++ to implement a stack using single linked list and
perform the following operations.
(a) isEmpty() is to check whether the stack is empty or not.
(b) push() is to insert an item in the stack.
(c) pop() is to delete an item from the stack.
(d) display() is to show the entire stack.*/

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
        void push(int value);
        void pop();
        void display();
};

void sll::is_empty(){
    if (head==NULL){
        cout<<"Stack is empty";
        return; 
    }
    cout<<"Stack is not empty";
    return;
}

void sll::push(int value){
    if(count < MAX -1){
        count++;
        node* new_node = new node;
        new_node->data = value;
        if (head ==NULL){
            head = new_node;
            new_node->next = NULL;
            return;
        }
        new_node->next = head;
        head = new_node;
    }
    else{
        cout<<"Stack overflow";
        return;
    }
    
}

void sll::pop(){
    if(head == NULL){
        cout<<"Stack underflow";
        return;
    }
    count--;
    node* temp = head;
    head = head->next;
    delete temp;
    return;
}

void sll::display(){
    if(head == NULL){
        cout<<"Empty stack";
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
    sll stack;
    int choice,value;
    do{
        cout<<"\nMenu\n";
        cout<<"1.)Is Empty\n";
        cout<<"2.)Push\n";
        cout<<"3.)Pop\n";
        cout<<"4.)Display\n";
        cout<<"0.)Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                stack.is_empty();
                break;
            case 2:
                cout<<"Enter element to push:";
                cin>>value;
                stack.push(value);
                break;
            case 3:
                stack.pop();
                break;
            case 4:
                stack.display();
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