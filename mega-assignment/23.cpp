/*Write a menu driven program in C or C++ to perform the following operations on Binary Search
Tree.

(a) insert a node.
(b) inorder traversal.
(c) Count the total number of external nodes.
(d) Count the total number of internal nodes.
(e) Determine the height of the tree.*/

#include<iostream>
#include<algorithm>
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
        int total_ext_nodes(node* root);
        int total_int_nodes(node* root);
        int height(node* root);
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

int bst::total_ext_nodes(node* root){
    if(root == NULL){
        return 0;
    }
    if(root->lchild == NULL && root->rchild == NULL){
        return 1;
    }
    return(total_ext_nodes(root->lchild) + total_ext_nodes(root->rchild));
}

int bst::total_int_nodes(node* root){
    if((root == NULL) || (root->lchild == NULL && root->rchild == NULL)){
        return 0;
    }
    return(total_int_nodes(root->lchild) + total_int_nodes(root->rchild)+1);
}

int bst::height(node* root){
    if(root == NULL){
        return 0;
    }
    return(max(height(root->lchild),height(root->rchild)) + 1);
}

int main(){
    bst tree;
    int choice,value,total;

    do{
        cout<<"\nMenu\n";
        cout<<"1) Insert node\n";
        cout<<"2) Inorder traversal\n";
        cout<<"3) Total external nodes\n";
        cout<<"4) Total internal nodes\n";
        cout<<"5) Height\n";
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
                total = tree.total_ext_nodes(tree.root);
                cout<<"Total external nodes = "<<total;
                break;
            case 4:
                total = tree.total_int_nodes(tree.root);
                cout<<"Total internal nodes = "<<total;
                break;
            case 5:
                total = tree.height(tree.root);
                cout<<"Height = "<<total;
                break;
        }
    }
    while(choice != 0);
    return 0;
}