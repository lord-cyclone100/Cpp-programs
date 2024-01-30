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
        void del_end();
        void display();
        void search(int value);
        void reverse();
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

void sll::search(int value){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == value){
            cout<<value<<" found";
            return;
        }
        temp = temp->next;
    }
    cout<<"Value not found";
    return;
}

void sll::reverse(){
    node *p=head,*q,*r=NULL;
    while (p!=NULL){
        q=p;
        p=p->next;
        q->next=r;
        r=q;
    }
    head = q;
    return;
}

int main(){

    sll list;
    int choice, value;

    do{
        cout<<"\nMenu\n";
        cout<<"1.)Insert element at beginning\n";
        cout<<"2.)Delete element from end\n";
        cout<<"3.)Display\n";
        cout<<"4.)Search element\n";
        cout<<"5.)Reverse\n";
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
                list.del_end();
                break;
            case 3:
                list.display();
                break;
            case 4:
                cout<<"Enter element to search:";
                cin>>value;
                list.search(value);
                break;
            case 5:
                list.reverse();
                break;
            case 0:
                break;
            default:
                cout<<"Invalid choice";
        }
    }
    while(choice != 0);


    return 0;
}