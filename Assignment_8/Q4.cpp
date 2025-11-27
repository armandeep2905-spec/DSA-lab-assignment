// Write a program to determine whether a given binary tree is a BST or not.
#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    int val;
    node *left;
    node *right;

    node(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }

    void inorder(node *root, vector<int> &bst)
    {
        if (root == NULL)
            return;
        inorder(root->left, bst);
   
        bst.push_back(root->val);
        inorder(root->right, bst);
    };

    bool isBST(vector<int> bst)
    {
        for (int i = 0; i < bst.size()-1; i++)
        {
            if (bst[i] > bst[i + 1])
                return false;
     
        }
        return true;
    }
};
int main()
{
    vector<int> bst;
    node *help = new node(100);
    node *a = new node(10);
    node *b = new node(5);
    node *c = new node(15);
    node *d = new node(2);
    node *e = new node(8);
    node *f = new node(11);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    help->inorder(a, bst);
    if (help->isBST(bst))
    {
        cout << "the given tree is a BST";
    }
    else
    {
        cout << "not a BST";
    }

    return 69;
}