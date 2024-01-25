#include<iostream>
using namespace std;
#define MAX_SIZE 5

class stack{
    private:
        int a[MAX_SIZE];
        int index;

    public:
        stack(){
            index = -1;
        }
        void is_full(){
            if(index >= MAX_SIZE - 1){
                cout<<"stack is full";
            }
            else{
                cout<<"stack is not full";
            }
            return;
        }

        void is_empty(){
            if(index == -1){
                cout<<"stack is empty";
            }
            else{
                cout<<"stack is not empty";
            }
            return;
        }

        void push(int value){
            index++;
            if (index > MAX_SIZE - 1){
                cout<<"stack overflow";
                return;
            }
            a[index] = value;
            return;
        }

        void pop(){
            if(index < 0){
                cout<<"stack underflow";
                return;
            }
            index--;
            return;
        }

        void display(){
            if(index < 0){
                cout<<"Empty stack";
            }
            for (int i=index;i>=0;i--){
                cout<<a[i]<<" ";
            }
        }

        void peek(){
            if(index < 0){
                cout<<"Empty stack";
                return;
            }
            cout<<"top element:"<<a[index];
            return;
        }

};

int main(){
    stack s;
    int value,choice;
    cout<<"Menu\n";
    cout<<"1.) Push\n";
    cout<<"2.) Pop\n";
    cout<<"3.) Display\n";
    cout<<"4.) Is full\n";
    cout<<"5.) Is empty\n";
    cout<<"6.) Peek\n";
    cout<<"7.) Exit\n";

    do{
        cout<<"\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value:";
                cin>>value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                s.is_full();
                break;

            case 5:
                s.is_empty();
                break;

            case 6:
                s.peek();
                break;

            case 0:
                cout<<"Exiting program....";
                break;

            default:
                cout<<"Please enter correct option\n";
                break;
        }
    }
    while (choice != 0);
    return 0;
}