//Program for simple execution of deletion function on BST
#include<iostream>
using namespace std;

class node{  //node class
public:
    int data;
    node* right;
    node* left;

node(int n){  //paramerterized constructor
    data=n;
    right=nullptr;
    left=nullptr;
}

node(){  //default constructor
    data=0;
    right=nullptr;
    left=nullptr;
}

node *insertn(node *root,int h){  //recursive function to insert an element
    if(root==nullptr)  //when root is NULL
        return new node(h);
    if(root->data==h){  //if root->data matches the value to be inserted
        cout<<"Already present!"<<endl;
        return root;
    }
    if(root->data<h)  //if root->data is less than h, value is to inserted in right subtree
        root->right=insertn(root->right,h);
    if(root->data>h)  //if root->data is greater than h, value is to inserted in left subtree
        root->left=insertn(root->left,h);

    return root;
}

void inorder(node* root){  //recursive function to traverse tree in inorder fashion
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){   //recursive function to traverse tree in preorder fashion
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(node* root){    //recursive function to traverse tree in postorder fashion
    if(root==nullptr)
        return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}

node* deleten(node*,int);
node* inordersuccessor(node* );

};

node* node::inordersuccessor(node *root){  //function to find the successor of the required node (only when right child ispresent)
    root=root->right;  //assigning to root of right subtree
    while(root!=nullptr&&root->left!=nullptr)  //until leftmost in right subtree is accessed
        root=root->left;
    return root;

}

node* node::deleten(node *root,int h){  //function to help r=delete a node
if(root==nullptr)  //if node's null
    return root;
else if(root->data>h)  //if required node is in left subtree
    root->left=deleten(root->left,h);
else if(root->data<h)  //if required node is in right subtree
    root->right=deleten(root->right,h);
else {  //if we got access to required node
    if(root->left==nullptr){  //if node to be deleted doesn't have left subtree, store the right subtree and delete the node, then return right node
        node *temp=root->right;
        delete root;
        return temp;
    }
    else if(root->right==nullptr){//if node to be deleted doesn't have right subtree, store the leftt subtree and delete the node, then return leftt node
        node* temp=root->left;
        delete root;
        return temp;
    }
    else{  //if node has both the children
        node* succ=inordersuccessor(root);  //find ans store its inorder successor in succ
        root->data=succ->data;  //change the data of the node with both choldren
        root->right=deleten(root->right,succ->data);  //delete the child node which was inorder successor of the required node
    }
}
return root;  //return root
}



int main(){
    cout<<"Make selection: "<<endl;
    node* root=nullptr;
    cout<<"1. Insert a node"<<endl;
    cout<<"2. Display inorder"<<endl;
    cout<<"3. Display preorder"<<endl;
    cout<<"4. Display postorder"<<endl;
    cout<<"5. delete an element"<<endl;

    int n;
    while(cin>>n){
        switch(n){
        case 1:
            cout<<"Enter value to be inserted: ";
            int h;
            cin>>h;
            root=root->insertn(root,h);
            break;
        case 2:
            if(root==nullptr)
                cout<<"Empty!";
            else root->inorder(root);
            cout<<endl;
            break;
        case 3:
            if(root==nullptr)
                cout<<"Empty!";
            else
            root->preorder(root);
            cout<<endl;
            break;
        case 4:
            if(root==nullptr)
                cout<<"Empty!";
            else
            root->postorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Enter element: ";
            int a;
            cin>>a;
            root=root->deleten(root,a);
            break;
        default:
            cout<<"Invalid selection!"<<endl;

        }
    }

}
