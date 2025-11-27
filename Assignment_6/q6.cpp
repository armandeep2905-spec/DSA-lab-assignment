#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next != head)
            temp = temp->next;

        temp->next = newNode;
    }

    // make the list circular (manually for testing)
    void makeCircular() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head; // last node points to head
    }

    // check if circular
    bool isCircular() {
        if (head == NULL)
            return false;

        Node* temp = head->next;
        while (temp != NULL && temp != head)
            temp = temp->next;

        return (temp == head);
    }
};

int main() {
    LinkedList list;
    list.insertEnd(2);
    list.insertEnd(4);
    list.insertEnd(6);
    list.insertEnd(7);
    list.insertEnd(5);

    list.makeCircular(); // making the list circular

    if (list.isCircular())
        cout << "Linked List is CIRCULAR";
    else
        cout << "Linked List is NOT CIRCULAR";

    return 0;
}
