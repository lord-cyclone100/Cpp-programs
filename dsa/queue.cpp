#include<iostream>
using namespace std;
#define MAX_SIZE 5

class queue{
    private:
        int a[MAX_SIZE];
        int index;
        int top;

    public:
        queue(){
            index = -1;
            top = 0;
        }
        void is_full(){
            if(index >= MAX_SIZE - 1){
                cout<<"queue is full";
            }
            else{
                cout<<"queue is not full";
            }
            return;
        }

        void is_empty(){
            if(index == -1){
                cout<<"queue is empty";
            }
            else{
                cout<<"queue is not empty";
            }
            return;
        }

        void enqueue(int value){
            index++;
            if (index > MAX_SIZE - 1){
                cout<<"queue overflow";
                return;
            }
            a[index] = value;
            return;
        }

        void dequeue(){
            if(index < 0){
                cout<<"queue underflow";
                return;
            }
            top++;
            return;
        }

        void display(){
            if(index < 0){
                cout<<"Empty queue";
            }
            for (int i=top;i<=index;i++){
                cout<<a[i]<<" ";
            }
        }

        void peek(){
            if(index < 0){
                cout<<"Empty queue";
                return;
            }
            cout<<"top element:"<<a[index];
            return;
        }

};

int main(){
    queue q;
    int value,choice;
    cout<<"Menu\n";
    cout<<"1.) Enqueue\n";
    cout<<"2.) Dequeue\n";
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
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                q.is_full();
                break;

            case 5:
                q.is_empty();
                break;

            case 6:
                q.peek();
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