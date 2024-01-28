#include <iostream>

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
        root  = NULL;
    }
    void insert_node(int value);
    void inorder(node* root);
    void preorder(node* root);
    void postorder(node* root);
    void search(int value);
    void find_smallest_element();
    int total_nodes(node* root);
    void find_largest_element();
    void delete_node(int value);
    int total_external_nodes(node* root);
    int total_internal_nodes(node* root);
};

void bst::insert_node(int value){
    node* new_node = new node;
    new_node->data = value;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    if (root == NULL){
        root = new_node;
        return;
    }
    node* temp = root, *parent;
    while (temp != NULL){
        parent = temp;
        if (value < temp->data){
            temp = temp->lchild;
        }
        else if (value > temp->data){
            temp = temp->rchild;
        }
        else{
            cout<<"Repeated data";
            return;
        }
    }
    if (value < parent->data){
        parent->lchild = new_node;
    }
    else{
        parent->rchild = new_node;
    }
    return;
}

void bst::inorder(node* root){  /* left -> root -> right*/
    if (root == NULL){
        return;
    }
    inorder (root->lchild);
    cout<<root->data<<" ";
    inorder (root->rchild);
}

void bst::preorder(node* root){  /* root -> left -> right*/
    if (root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->lchild);
    preorder(root->rchild);
}

void bst::postorder(node* root){  /* left -> right -> root*/
    if (root == NULL){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data<<" ";
}

void bst::search(int value){
    if (root == NULL){
        cout<<"Empty tree";
        return;
    }
    node* curr = root;
    while (curr != NULL){
        if (value == curr->data){
            cout<<value<<" found";
            return;
        }
        else if(value > curr->data){
            curr = curr->rchild;
        }
        else if(value < curr->data){
            curr = curr->lchild;
        }
    }
    cout<<value<<" not found";
    return;
}

void bst::find_smallest_element(){
    if (root == NULL){
        cout<<"Empty tree";
        return;
    }
    node* curr = root;
    while (curr->lchild != NULL){
        curr = curr->lchild;
    }
    cout<<curr->data;
    return;
}

void bst::find_largest_element(){
    if (root == NULL){
        cout<<"Empty tree";
        return;
    }
    node* curr = root;
    while (curr->rchild != NULL){
        curr = curr->rchild;
    }
    cout<<curr->data;
    return;
}

int bst::total_nodes(node* root){
    if (root == NULL){
        return 0;
    }
    return (total_nodes(root->lchild) + total_nodes(root->rchild) + 1);
}

void bst::delete_node(int value){
    if (root == NULL){
        cout<<"Empty tree";
        return;
    }
    node* x = root;
    node* parent = NULL;
    while (x != NULL && x->data != value){
        parent = x;
        if (value < x->data){
            x = x->lchild;
        }
        else{
            x = x->rchild;
        }
    }
    if (x == NULL){
        cout<<"Value not found";
        return;
    }
    if (x->lchild == NULL || x->rchild == NULL){
        node* ptr = NULL;
        if (x->lchild == NULL){
            ptr = x->rchild;
        }
        else{
            ptr = x->lchild;
        }
        if (parent == NULL){
            delete root;
            root = ptr;
            return;
        }
        if (x = parent->lchild){
            parent -> lchild = ptr;
        }
        else{
            parent -> rchild = ptr;
        }
        delete x;
        return;
    }
    else{
        node* succ = x->rchild;
        node* psucc = NULL;
        while (succ->lchild != NULL){
            psucc = succ;
            succ = succ->lchild;
        }
        x->data = succ->data;
        if (psucc == NULL){
            x->rchild == succ->rchild;
        }
        else{
            psucc->lchild = succ->rchild;
        }
        delete succ;
        return;
    }
}

int bst::total_external_nodes(node* root){
    if (root == NULL){
        return 0; 
    }
    if ((root->lchild == NULL) && (root->rchild == NULL)){
        return 1;
    }
    return (total_external_nodes(root->lchild) + total_external_nodes(root->rchild));
}

int bst::total_internal_nodes(node* root){
    if ((root == NULL) || ((root->lchild == NULL) && (root->rchild == NULL))){
        return 0;
    }
    int t = total_nodes(root);
    int e = total_external_nodes(root);
    return (t - e);
}

int main()
{
    bst tree;
    int value,choice;
    node* root;
    
    cout<<"Menu"<<endl;
    cout<<"1.) Insert node"<<endl;
    cout<<"2.) Inorder traversal"<<endl;
    cout<<"3.) Preorder traversal"<<endl;
    cout<<"4.) Postorder traversal"<<endl;
    cout<<"5.) Search element"<<endl;
    cout<<"6.) Find smallest element"<<endl;
    cout<<"7.) Find largest element"<<endl;
    cout<<"8.) Delete node"<<endl;
    cout<<"9.) Total nodes"<<endl;
    cout<<"10.) Total external nodes"<<endl;
    cout<<"11.) Total internal nodes"<<endl;
    cout<<"0.) Exit"<<endl;
    do{
        cout<<"\nEnter your choice:";
        cin>>choice;
        
        switch(choice){
            case 1:
                cout<<"\nEnter value:";
                cin>>value;
                tree.insert_node(value);
                break;
            case 2:
                cout<<"\nInorder traversal:";
                tree.inorder(tree.root);
                break;
            case 3:
                cout<<"\nPreorder traversal:";
                tree.preorder(tree.root);
                break;
            case 4:
                cout<<"\nPostorder traversal:";
                tree.postorder(tree.root);
                break;
            case 5:
                cout<<"\nEnter value to search:";
                cin>>value;
                tree.search(value);
                break;
            case 6:
                cout<<"\nSmallest element:";
                tree.find_smallest_element();
                break;
            case 7:
                cout<<"\nLargest element:";
                tree.find_largest_element();
                break;
            case 8:
                cout<<"\nEnter value:";
                cin>>value;
                tree.delete_node(value);
                break;  
            case 9:
                int total1;
                total1 = tree.total_nodes(tree.root);
                cout<<"\nTotal nodes:"<<total1;
                break;
            case 10:
                int total2;
                total2 = tree.total_external_nodes(tree.root);
                cout<<"\nTotal external nodes:"<<total2;
                break;
            case 11:
                int total3;
                total3 = tree.total_internal_nodes(tree.root);
                cout<<"\nTotal internal nodes:"<<total3;
                break;
            default:
                cout<<"Please enter correct option\n";
                break;
            case 0:
                cout<<"\nExiting program...";
                break;
        }
    }
    while (choice != 0);

    return 0;
}