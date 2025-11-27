#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Function to find size
    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
int main() {
    DoublyLinkedList dll;
    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);

    cout << "Size of Doubly Linked List = " << dll.size() << endl;
    return 0;
}
