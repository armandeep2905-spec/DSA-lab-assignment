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

class DoublyLL {
public:
    Node* head;
    DoublyLL() {
        head = NULL;
    }

    // Insert at beginning
    void insertFirst(int val) {
        Node* newNode = new Node(val);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert at end
    void insertLast(int val) {
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

    // Insert after a given value
    void insertAfter(int val, int afterVal) {
        Node* temp = head;
        while (temp != NULL && temp->data != afterVal)
            temp = temp->next;

        if (temp == NULL) {
            cout << afterVal << " not found!" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Insert before a given value
    void insertBefore(int val, int beforeVal) {
        if (head == NULL) return;

        if (head->data == beforeVal) {
            insertFirst(val);
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != beforeVal)
            temp = temp->next;

        if (temp == NULL) {
            cout << beforeVal << " not found!" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    // Delete node by value
    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != val)
            temp = temp->next;

        if (temp == NULL) {
            cout << val << " not found!" << endl;
            return;
        }

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }

    // Search node
    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
        }
        cout << "Node not found!" << endl;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLL list;
    int choice, val, x;

    while (true) {
        cout << "\n====== MENU ======\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert After\n";
        cout << "4. Insert Before\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                list.insertFirst(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                list.insertLast(val);
                break;
            case 3:
                cout << "Enter new value & after which value: ";
                cin >> val >> x;
                list.insertAfter(val, x);
                break;
            case 4:
                cout << "Enter new value & before which value: ";
                cin >> val >> x;
                list.insertBefore(val, x);
                break;
            case 5:
                cout << "Enter value to delete: "; cin >> val;
                list.deleteNode(val);
                break;
            case 6:
                cout << "Enter value to search: "; cin >> val;
                list.search(val);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!";
        }
    }
}