#include <iostream>
using namespace std;
class node
{
public:
    int val;
    node *left = NULL;
    node *right = NULL;

    node(int a) : val(a) {};

    void search(node *root, int target)
    {
        if (root == NULL)
        {
            cout << "target not found";
            return;
        }
        else if (root->val == target)
        {
            cout << "target found";
        }
        else if (target < root->val)
            search(root->left, target);
        else if (target > root->val)
            search(root->right, target);
        else
            cout << "target not found";
    }

    int TreeMin(node *root)
    {
        if (root == NULL)
        {
            cout << "Tree is empty";
            return 0;
        }
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root->val;
    }

    int TreeMax(node *root)
    {
        if (root == NULL)
        {
            cout << "Tree is empty";
            return 0;
        }
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root->val;
    }


    node* predecessor(node* root){
    if(root->left==NULL) return NULL;
    node *pred=root->left;
    while(pred->right!=NULL){
        pred=pred->right;
      
    }  return pred;
}

node* successor(node* root){
    if(root->right==NULL) return NULL;
    node *succ=root->right;
    while(succ->left!=NULL){
        succ=succ->left;
      
    }  return succ;
}
};

int main()
{//BST->
    node *help = new node(100);
    node *a = new node(10);
    node *b = new node(5);
    node *c = new node(15);
    node *d = new node(2);
    node *e = new node(8);
    node *f = new node(11);
    node *g = new node(19);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = g;
    c->left = f;
    
    //SEARCH FUNTION->
    int target;
    cout << "targeted value: ";
    cin >> target;
    a->search(a, target);
    cout << endl;

//MAX AND MIN ELEMENT OF BST->
    cout << "max element is:" << help->TreeMax(a) << endl;
    cout << "min element is:" << help->TreeMin(a) << endl;

//PREDECESSOR AND SUCCESSOR->
node *pred=help->predecessor(a);
cout<<"predecessor is:"<<pred->val<<endl;
node *succ=help->predecessor(b);
cout<<"successor is:"<<succ->val<<endl;

}