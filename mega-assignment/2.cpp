/*Write a menu driven program in C/C++ to implement a Stack using array and perform the
 following operations.
 (a) isFull() function to check whether the Stack is full or not.
 (b) isEmpty() function to check whether the Stack is empty or not.
 (c) peek() function to read the stack top element without deleting it.
 (d) push(item) function to insert an element item in the Stack.
 (e) pop() function to read and remove an element from the Stack.
 (f) display() function to display the entire stack.*/

#include<iostream>
using namespace std;
#define MAX 5

class stack{
    private:
        int arr[MAX];
        int top;
    public:
        stack(){
            top = -1;
        }
        void is_full(){
            if (top == MAX - 1){
                cout<<"Stack is full";
                return;
            }
            else{
                cout<<"Stack is not full";
                return;
            }
        }
        void is_empty(){
            if (top == -1){
                cout<<"Stack is empty";
                return;
            }
            else{
                cout<<"Stack is not empty";
                return;
            }
        }
        void peek(){
            if (top == -1){
                cout<<"Stack is empty";
                return;
            }
            cout<<"Top element = "<<arr[top];
            return;
        }
        void push(int value){
            if(top >= MAX-1){
                cout<<"Stack overflow";
                return;
            }
            top++;
            arr[top] = value;
            return;
        }
        void pop(){
            if(top<=-1){
                cout<<"Stack underflow";
                return;
            }
            top--;
            return;
        }
        void display(){
            if(top == -1){
                cout<<"Stack is empty";
                return;
            }
            for(int i = top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            return;
        }

};

int main(){
    stack s;
    int choice,value;

    do{
        cout<<"\nMenu\n";
        cout<<"1.)Is Full\n";
        cout<<"2.)Is Empty\n";
        cout<<"3.)Peek\n";
        cout<<"4.)Push\n";
        cout<<"5.)Pop\n";
        cout<<"6.)Display\n";
        cout<<"0.)Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice){
            case 1:
                s.is_full();
                break;
            case 2:
                s.is_empty();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                cout<<"Enter element to push:";
                cin>>value;
                s.push(value);
                break;
            case 5:
                s.pop();
                break;
            case 6:
                s.display();
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