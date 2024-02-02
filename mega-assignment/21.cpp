/*Write a menu driven program in C or C++ to perform the following operations on Binary Search
Tree.
(a) insert a node.
(b) inorder traversal.
(c) preorder traversal.
(d) search an given key.
(e) Find the smallest element.*/

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* lchild;
        node* rchild;
};

class bst{
    public:
        node* root;
        bst(){
            root = NULL;
        }
        void insert_node(int value);
        void inorder(node* root);
        void preorder(node* root);
        void search_node(int value);
        void smallest_element(node* root);
};

void bst::insert_node(int value){
    node* new_node = new node;
    new_node->data = value;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    if(root == NULL){
        root = new_node;
        return;
    }
    node* temp = root,*parent;
    while(temp != NULL){
        parent = temp;
        if(value > temp->data){
            temp = temp->rchild;
        }
        else if(value < temp->data){
            temp = temp->lchild;
        }
        else{
            cout<<"Repeated data";
            return;
        }
    }
    if(value > parent->data){
        parent->rchild = new_node;
    }
    else{
        parent->lchild = new_node;
    }
    return;
}

void bst::inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->lchild);
    cout<<root->data<<" ";
    inorder(root->rchild);
}

void bst::preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->lchild);
    preorder(root->rchild);
    
}

void bst::search_node(int value){
    if(root == NULL){
        cout<<"Empty tree";
        return;
    }
    node* temp = root;
    while(temp != NULL){
        if(value == temp->data){
            cout<<value<<" found";
            return;
        }
        else if(value < temp->data){
            temp = temp->lchild;
        }
        else if(value > temp->data){
            temp = temp->rchild;
        }
    }
    cout<<value<<" Not found";
    return;
}

void bst::smallest_element(node* root){
    if(root == NULL){
        cout<<"Empty tree";
        return;
    }
    node* temp = root;
    while(temp->lchild != NULL){
        temp = temp->lchild;
    }
    cout<<"Smallest element = "<<temp->data;
    return;
}

int main(){

    bst tree;
    int choice,value;
    do{
        cout<<"\nMenu\n";
        cout<<"1) Insert node\n";
        cout<<"2) Inorder traversal\n";
        cout<<"3) Preorder traversal\n";
        cout<<"4) Search element\n";
        cout<<"5) Smallest element\n";
        cout<<"0) Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to insert:";
                cin>>value;
                tree.insert_node(value);
                break;
            case 2:
                tree.inorder(tree.root);
                break;
            case 3:
                tree.preorder(tree.root);
                break;
            case 4:
                cout<<"Enter value to search:";
                cin>>value;
                tree.search_node(value);
                break;
            case 5:
                tree.smallest_element(tree.root);
                break;
        }
    }
    while(choice != 0);



    return 0;
}