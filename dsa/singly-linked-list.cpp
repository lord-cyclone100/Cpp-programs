#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

class sll{
    private:
        node* head;
    public:
        sll(){
            head = NULL;
        }
        void ins_beg(int value);
		void ins_end(int value);
		void del_beg();
		void del_end();
		void del_value(int value);
        int search(int value);
		void display_beg();
		void display_end();
        void bubble_sort();
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

void sll::ins_end(int value){
    node* new_node = new node;
    new_node->data = value;
    if(head == NULL){
        new_node->next = NULL;
        head = new_node;
        return;
    }
    node*temp = head;
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
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    node* temp = head;
    node* prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    return;
}

void sll::display_beg(){
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

int sll::search(int value){
    if(head == NULL){
        return -1;
    }
    node* temp = head;
    while(temp != NULL){
        if(temp->data == value){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void sll::del_value(int value){
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    if(head->next == NULL && head->data == value){
        delete head;
        head = NULL;
        return;
    }
    node* temp = head;
    node* prev = NULL;
    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<value<<" not found";
        return;
    }
    prev->next = temp->next;
    delete temp;
    return;
}

void sll::display_end(){
    sll l;
    if(head == NULL){
        cout<<"Empty list";
        return;
    }
    node* temp = head;
    while(temp != NULL){
        l.ins_beg(temp->data);
        temp = temp->next;
    }
    l.display_beg();
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

void sll::bubble_sort() {
    if (head == NULL) {
        cout << "Empty list";
        return;
    }
    node* temp = head;
    node* end = NULL;
    while (temp != end) {
        while (temp->next != end) {
            if (temp->data > temp->next->data) {
                int t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp = temp->next;
        }
        end = temp;
        temp = head;
    }
}

int main(){

    sll list;
    int value,choice,s;

    cout<<"Menu\n";
    cout<<"1.)Insert beginning\n";
    cout<<"2.)Insert end\n";
    cout<<"3.)Delete beginning\n";
    cout<<"4.)Delete end\n";
    cout<<"5.)Delete value\n";
    cout<<"6.)Search value\n";
    cout<<"7.)Display from beginning\n";
    cout<<"8.)Display from end\n";
    cout<<"9.)Reverse the list\n";
    cout<<"10.)Bubble sort\n";
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
                cout<<"Enter value:";
                cin>>value;
                s = list.search(value);
                if(s==-1){
                    cout<<"Empty list";
                }
                else if(s==1){
                    cout<<value<<" found";
                }
                else if(s==0){
                    cout<<value<<" not found";
                }
                break;

            case 7:
                list.display_beg();
                break;

            case 8:
                list.display_end();
                break;

            case 9:
                list.reverse();
                break;

            case 10:
                list.bubble_sort();
                break;

            case 0:
                cout<<"Exiting program....";
                break;

            default:
                cout<<"Please enter correct option";
                break;
        }
    }
    while(choice != 0);

    return 0;
}