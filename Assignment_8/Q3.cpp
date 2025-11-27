#include <iostream>
#include<limits>

using namespace std;
class node
{
public:
    int val;
    node *left = NULL;
    node *right = NULL;

    node(int a) : val(a) {};
    bool insertion(node *root, int target)
    {

        if (target == root->val)
        {
            cout << "already exists in the tree" << endl;
            return false;
        }

        if (target > root->val)
        { // go right
            if (root->right == NULL)
            {
                root->right = new node(target);
                return true;
            }
            return insertion(root->right, target);
        }

        if (target < root->val)
        { // go left
            if (root->left == NULL)
            {
                root->left = new node(target);
                return true;
            }
            return insertion(root->left, target);
        }

        return false;
    }

    void display(node *root)
    {
        if (root == NULL)
            return;

        display(root->left);
        cout << root->val << " ";
        display(root->right);
    }
    int Maxdepth(node* root){
        if(root==NULL ) return 0;
        int left=Maxdepth(root->left);
        int right=Maxdepth(root->right);
        return 1+max(left,right);
    }

   int MinDepth(node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL)
        return 1 + MinDepth(root->right);

    if (root->right == NULL)
        return 1 + MinDepth(root->left);

    return 1 + min(MinDepth(root->left), MinDepth(root->right));
}

};

int main()
{ // BST->
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
    help->display(a);
    cout << endl;
    int target;
    cout << "enter the value to be inserted: " << endl;
    cin >> target;

    // insertion->
    if (help->insertion(a, target) == true)
    {
        cout << "After insertion: ";
        help->display(a);
        cout << endl;
    }

    cout<<"Maximum depth of the tree: "<<help->Maxdepth(a)<<endl<<"Minimum depth of the tree: "<<help->MinDepth(a);
}