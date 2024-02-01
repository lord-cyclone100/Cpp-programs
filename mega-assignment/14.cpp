/*14. Write a program in C or C++ to add two polynomials using linked list.*/

#include<iostream>
using namespace std;

class node{
    public:
        int coeff;
        int expo;
        node* next;
};

class poly{
    private:
        node* head;
    public:
        poly(){
            head = NULL;
        }
        void ins_poly(int coeff,int expo);
        void display_poly();
        node* get_head();
        void add_poly(poly p1,poly p2,poly &p3);
};

void poly::ins_poly(int c,int e){
    if(e < 0){
        cout<<"Invalid exponent";
        return;
    }
    node* new_node = new node;
    new_node->coeff = c;
    new_node->expo = e;
    if(head == NULL || head->expo < new_node->expo){
        new_node->next = head;
        head = new_node;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        if(new_node->expo < temp->expo && new_node->expo > temp->next->expo){
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        if(new_node->expo == temp->expo || new_node->expo == temp->next->expo){
            cout<<"Same exponents not allowed";
        }
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
    return;
}

void poly::display_poly(){
    if(head == NULL){
        cout<<"Empty polynomial";
        return;
    }
    node* temp = head;
    while(temp != NULL){
        cout<<temp->coeff<<"x^"<<temp->expo;
        if(temp->next != NULL){
            cout<<" + ";
        }
        temp = temp->next;
    }
}

node* poly::get_head(){
    return head;
}

void poly::add_poly(poly p1,poly p2,poly &p3){
    node* temp1 = p1.get_head();
    node* temp2 = p2.get_head();
    while(temp1 != NULL || temp2!= NULL){
        if(temp1 == NULL){
            p3.ins_poly(temp2->coeff,temp2->expo);
            temp2 = temp2->next;
        }
        else if(temp2 == NULL){
            p3.ins_poly(temp1->coeff,temp1->expo);
            temp1 = temp1->next;
        }
        else{
            if(temp1->expo == temp2->expo){
                p3.ins_poly((temp1->coeff+temp2->coeff),temp1->expo);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if(temp1->expo > temp2->expo){
                p3.ins_poly(temp1->coeff,temp1->expo);
                temp1 = temp1->next;
            }
            else{
                p3.ins_poly(temp2->coeff,temp2->expo);
                temp2 = temp2->next;
            }
        }
    }
}

int main(){

    poly p1,p2,p3;
    int t,c_value,e_value;

    cout<<"Enter number of terms of 1st polynomial:";
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Enter coefficient:";
        cin>>c_value;
        cout<<"Enter exponent:";
        cin>>e_value;
        p1.ins_poly(c_value,e_value);
    }
    cout<<"Polynomial 1:";
    p1.display_poly();

    cout<<endl;

    cout<<"Enter number of terms of 2nd polynomial:";
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Enter coefficient:";
        cin>>c_value;
        cout<<"Enter exponent:";
        cin>>e_value;
        p2.ins_poly(c_value,e_value);
    }
    cout<<"Polynomial 1:";
    p2.display_poly();

    p3.add_poly(p1,p2,p3);
    cout<<endl;
    cout<<"Polynomial Addition:";
    p3.display_poly();



    return 0;
}