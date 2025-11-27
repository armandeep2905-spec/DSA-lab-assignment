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

class CircularLL {
public:
    Node* head;

    CircularLL() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    // Insert before a given value
    void insertBefore(int val, int beforeVal) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        // If inserting before head
        if (head->data == beforeVal) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        while (temp->next != head && temp->next->data != beforeVal)
            temp = temp->next;

        if (temp->next == head) {
            cout << beforeVal << " not found!\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Insert after a given value
    void insertAfter(int val, int afterVal) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        while (temp->data != afterVal && temp->next != head)
            temp = temp->next;

        if (temp->data != afterVal) {
            cout << afterVal << " not found!\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete specific node
    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        // If deleting head
        if (head->data == val) {
            while (temp->next != head)
                temp = temp->next;

            if (temp == head) {   // only 1 node
                delete head;
                head = NULL;
                return;
            }

            temp->next = head->next;
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        // Delete node in between
        temp = head;
        while (temp->next != head && temp->next->data != val)
            temp = temp->next;

        if (temp->next == head) {
            cout << val << " not found!\n";
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    // Search for a node
    void search(int val) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        int pos = 1;
        Node* temp = head;
        do {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Node not found\n";
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    CircularLL cll;
    int choice, val, x;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Value\n";
        cout << "4. Insert After a Value\n";
        cout << "5. Delete a Node\n";
        cout << "6. Search a Node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtBeginning(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                cll.insertAtEnd(val);
                break;

            case 3:
                cout << "Enter new value & value before which it should be inserted: ";
                cin >> val >> x;
                cll.insertBefore(val, x);
                break;

            case 4:
                cout << "Enter new value & value after which it should be inserted: ";
                cin >> val >> x;
                cll.insertAfter(val, x);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> val;
                cll.deleteNode(val);
                break;

            case 6:
                cout << "Enter value to search: ";
                cin >> val;
                cll.search(val);
                break;

            case 7:
                cll.display();
                break;

            case 8:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
