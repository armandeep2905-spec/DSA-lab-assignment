#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char ch) {
        data = ch;
        next = prev = NULL;
    }
};

class DoublyLL {
public:
    Node* head;

    DoublyLL() {
        head = NULL;
    }

    // Insert at end
    void insertEnd(char ch) {
        Node* newNode = new Node(ch);
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

    // Check palindrome
    bool isPalindrome() {
        if (head == NULL || head->next == NULL)
            return true;

        Node* left = head;
        Node* right = head;

        // move right to last node
        while (right->next != NULL)
            right = right->next;

        // compare from both ends
        while (left != right ) {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyLL dll;
    dll.insertEnd('r');
    dll.insertEnd('a');
    dll.insertEnd('d');
    dll.insertEnd('a');
    dll.insertEnd('r');

    if (dll.isPalindrome())
        cout << "Linked List is Palindrome";
    else
        cout << "Linked List is NOT Palindrome";

    return 0;
}
