/*Write a menu driven program in C or C++ to perform the following operations on Binary Search
Tree.
(a) insert a node.
(b) inorder traversal.
(c) postorder traversal.
(d) Find the largest element.
(e) Count the total number of nodes.*/

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
        void postorder(node* root);
        void largest_element(node* root);
        int total_nodes(node* root);
};

void bst::insert_node(int value){
    node*new_node = new node;
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
            cout<<"Duplicate value";
            return;
        }
    }
    if(value > parent->data){
        parent->rchild = new_node;
    }
    else if(value < parent->data){
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

void bst::postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data<<" ";
}

void bst::largest_element(node* root){
    if(root == NULL){
        cout<<"Empty tree";
        return;
    }
    node* temp = root;
    while(temp->rchild != NULL){
        temp = temp->rchild;
    }
    cout<<"Largest element = "<<temp->data;
}

int bst::total_nodes(node* root){
    if(root == NULL){
        return 0;
    }
    return(total_nodes(root->lchild) + total_nodes(root->rchild) + 1);
}


int main(){
    bst tree;
    int choice,value,total;

    do{
        cout<<"\nMenu\n";
        cout<<"1) Insert node\n";
        cout<<"2) Inorder traversal\n";
        cout<<"3) Postorder traversal\n";
        cout<<"4) Largest element\n";
        cout<<"5) Total nodes\n";
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
                tree.postorder(tree.root);
                break;
            case 4:
                tree.largest_element(tree.root);
                break;
            case 5:
                total = tree.total_nodes(tree.root);
                cout<<"Total nodes = "<<total;
                break;
        }
    }
    while(choice != 0);
    return 0;
}