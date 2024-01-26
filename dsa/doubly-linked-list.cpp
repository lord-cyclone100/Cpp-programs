#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;
};

class dll{
    private:
        node* head;
    public:
        dll(){
            head =NULL;
        }
        void ins_beg(int value);
		void ins_end(int value);
		void del_beg();
		void del_end();
		void del_value(int value);
        void search(int value);
		void display_beg();
		void display_end();
};

void dll::ins_beg(int value){
    node* new_node = new node;
    new_node->data = value;
    if(head == NULL){
        new_node->next = NULL;
        new_node->prev = NULL;
        head = new_node;
        return;
    }
    new_node->next = head;
    new_node->prev = NULL;
    head->prev=new_node;
    head = new_node;
    return;
}

void dll::ins_end(int value){
    node* new_node = new node;
    new_node->data = value;
    if(head == NULL){
        new_node->next = NULL;
        new_node->prev = NULL;
        head = new_node;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL;
    return;
}

void dll::del_beg(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    else{
        node* temp = head;
        head = head->next;
        if(head == NULL){
            delete temp;
            return;
        }
        head->prev = NULL;
        delete temp;
        return;
    }
}

void dll::del_end(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev == NULL){
        delete temp;
        delete head;
        head = NULL;
        return;
    }
    temp->prev->next = NULL;
    delete temp;
    return;
}

void dll::del_value(int value){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    //node* temp = head;
    if(head->data == value){
        dll::del_beg();
        return;
    }
    node* temp = head;
    while (temp->next != NULL){
        if(temp->data == value){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
    }
    if(temp->data == value){
        dll::del_end();
        return;
    }
    cout<<value<<" not found";
    return;
}

void dll::display_beg(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return;
}

void dll::display_end(){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    return;
}

void dll::search(int value){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node* temp = head;
    while(temp != NULL){
        if(temp->data == value){
            cout<<value<<" found";
            return;
        }
        temp = temp->next;
    }
    cout<<value<<" not found";
    return;
}

int main(){

    dll list;
    int value,choice;

    cout<<"Menu\n";
    cout<<"1.)Insert from beginning\n";
    cout<<"2.)Insert from end\n";
    cout<<"3.)Delete from beginning\n";
    cout<<"4.)Delete from end\n";
    cout<<"5.)Delete value\n";
    cout<<"6.)Display from beginning\n";
    cout<<"7.)Display from end\n";
    cout<<"8.)Search value\n";
    cout<<"0.)Exit\n";

    do{
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value:";
                cin>>value;
                list.ins_beg(value);
                break;

            case 2:
                cout<<"Enter value:";
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
                cout<<"Enter value:";
                cin>>value;
                list.del_value(value);
                break;

            case 6:
                list.display_beg();
                break;

            case 7:
                list.display_end();
                break;

            case 8:
                cout<<"Enter value:";
                cin>>value;
                list.search(value);
                break;

            case 0:
                cout<<"Exiting program....";
                break;
        }
    }
    while(choice != 0);

    return 0;
}