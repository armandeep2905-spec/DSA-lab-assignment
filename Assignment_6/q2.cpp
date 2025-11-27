#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value)
    {
        data=value;
        next=NULL;
    }

};

void displayCircular(Node* head)
{
    if(head==NULL)
    {
    cout<<"empty";
    return;
    }

    Node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    }while(temp!=head);

    cout<<head->data;

}

int main()
{
     Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    cout<<"printing the circular linked lis";

    head->next = second;
    second->next = third;
    third->next = head;
    displayCircular(head);
    return 0;
}