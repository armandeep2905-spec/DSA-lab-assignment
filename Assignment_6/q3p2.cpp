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

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head; // circular
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    int size() {
        if (head == NULL) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertEnd(5);
    cll.insertEnd(10);
    cll.insertEnd(15);

    cout << "Size of Circular Linked List = " << cll.size() << endl;
    return 0;
}
