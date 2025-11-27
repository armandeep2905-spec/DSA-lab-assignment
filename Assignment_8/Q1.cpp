//Write program using functions for binary tree traversals: Pre-order, In-order and Post
//order using recursive approach.

#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* left=NULL;
    node* right=NULL;

    node(int a):val(a){};
public:
    void preorder(node *root){
        if(root==NULL) return;
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    
    }
void inorder(node *root){
        if(root==NULL) return; 
        inorder(root->left);
        cout<<root->val<<" ";
       
        inorder(root->right);
    
    }
void postorder(node *root){
        if(root==NULL) return;
        
        postorder(root->left);
        postorder(root->right);
    cout<<root->val<<" ";
    }


};
int main(){

    node *a = new node(1);
    node *b = new node(2);
    node *c = new node(3);
    node *d = new node(4);
    node *e = new node(5);
    node *f = new node(6);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    cout<<"preorder traversal:";
    a->preorder(a);
    cout<<endl;
    cout<<"inorder traversal:";
    a->inorder(a);
    cout<<endl;
    cout<<"postorder traversal:";
    a->postorder(a);

}