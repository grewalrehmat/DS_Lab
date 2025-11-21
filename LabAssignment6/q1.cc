#include <iostream>
using namespace std;

// ================= NODE STRUCTURES ================
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

// =============== CIRCULAR LINKED LIST =============

class CLL {
public:
    Node* head;

    CLL() { head = NULL; }

    void insertBegin(int x) {
        Node* n = new Node(x);
        if (!head) {
            n->next = n;
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        n->next = head;
        temp->next = n;
        head = n;
    }

    void insertEnd(int x) {
        if (!head) { insertBegin(x); return; }
        Node* n = new Node(x);
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    void insertAfter(int key, int x) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* n = new Node(x);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found.\n";
    }

    void insertBefore(int key, int x) {
        if (!head) return;

        if (head->data == key) {
            insertBegin(x);
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        do {
            if (temp->data == key) {
                Node* n = new Node(x);
                n->next = temp;
                prev->next = n;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Node not found.\n";
    }

    void deleteNode(int key) {
        if (!head) return;

        Node* temp = head;
        Node* prev = NULL;

        if (temp->data == key) {
            if (temp->next == head) {
                delete temp;
                head = NULL;
                return;
            }
            while (temp->next != head) temp = temp->next;
            Node* del = head;
            temp->next = head->next;
            head = head->next;
            delete del;
            return;
        }

        temp = head;
        do {
            if (temp->data == key) {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Node not found.\n";
    }

    void search(int key) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Not Found\n";
    }

    void display() {
        if (!head) {
            cout << "Empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }

    void displayRepeatHead() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << "\n";
    }

    int size() {
        if (!head) return 0;
        Node* temp = head;
        int c = 0;
        do {
            c++;
            temp = temp->next;
        } while (temp != head);
        return c;
    }
};

// ================= DOUBLY LINKED LIST =============

class DLL {
public:
    Node* head;

    DLL() { head = NULL; }

    void insertBegin(int x) {
        Node* n = new Node(x);
        if (head) {
            n->next = head;
            head->prev = n;
        }
        head = n;
    }

    void insertEnd(int x) {
        if (!head) { insertBegin(x); return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        Node* n = new Node(x);
        temp->next = n;
        n->prev = temp;
    }

    void insertAfter(int key, int x) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                Node* n = new Node(x);
                n->next = temp->next;
                n->prev = temp;
                if (temp->next) temp->next->prev = n;
                temp->next = n;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found\n";
    }

    void insertBefore(int key, int x) {
        if (!head) return;

        if (head->data == key) {
            insertBegin(x);
            return;
        }

        Node* temp = head->next;
        while (temp) {
            if (temp->data == key) {
                Node* n = new Node(x);
                n->next = temp;
                n->prev = temp->prev;
                temp->prev->next = n;
                temp->prev = n;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found\n";
    }

    void deleteNode(int key) {
        if (!head) return;

        if (head->data == key) {
            Node* del = head;
            head = head->next;
            if (head) head->prev = NULL;
            delete del;
            return;
        }

        Node* temp = head->next;
        while (temp) {
            if (temp->data == key) {
                temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found\n";
    }

    void search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) { cout << "Found\n"; return; }
            temp = temp->next;
        }
        cout << "Not Found\n";
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    int size() {
        int c = 0;
        Node* temp = head;
        while (temp) {
            c++;
            temp = temp->next;
        }
        return c;
    }

    bool isPalindrome() {
        if (!head) return true;

        Node* left = head;
        Node* right = head;

        while (right->next) right = right->next;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};


bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head) temp = temp->next;
    return temp == head;
}


int main() {
    CLL cll;
    DLL dll;

    int choice;

    while (true) {
        cout << "\n\n====== MAIN MENU ======\n";
        cout << "1. Circular Linked List Menu\n";
        cout << "2. Doubly Linked List Menu\n";
        cout << "3. Check if Linked List is Circular\n";
        cout << "4. Exit\n";
        cout << "Enter: ";
        cin >> choice;


        if (choice == 1) {
            while (true) {
                int ch, val, key;
                cout << "\n--- CLL MENU ---\n";
                cout << "1.InsertBegin  2.InsertEnd\n";
                cout << "3.InsertAfter   4.InsertBefore\n";
                cout << "5.Delete        6.Search\n";
                cout << "7.Display       8.Display (Repeat Head)\n";
                cout << "9.Size          10.Back\n";
                cout << "Enter: ";
                cin >> ch;

                if (ch == 10) break;

                switch (ch) {
                    case 1: cin >> val; cll.insertBegin(val); break;
                    case 2: cin >> val; cll.insertEnd(val); break;
                    case 3: cin >> key >> val; cll.insertAfter(key,val); break;
                    case 4: cin >> key >> val; cll.insertBefore(key,val); break;
                    case 5: cin >> key; cll.deleteNode(key); break;
                    case 6: cin >> key; cll.search(key); break;
                    case 7: cll.display(); break;
                    case 8: cll.displayRepeatHead(); break;
                    case 9: cout << "Size = " << cll.size() << "\n"; break;
                }
            }
        }

        else if (choice == 2) {
            while (true) {
                int ch, val, key;
                cout << "\n--- DLL MENU ---\n";
                cout << "1.InsertBegin   2.InsertEnd\n";
                cout << "3.InsertAfter    4.InsertBefore\n";
                cout << "5.Delete         6.Search\n";
                cout << "7.Display        8.Size\n";
                cout << "9.Palindrome?    10.Back\n";
                cout << "Enter: ";
                cin >> ch;

                if (ch == 10) break;

                switch (ch) {
                    case 1: cin >> val; dll.insertBegin(val); break;
                    case 2: cin >> val; dll.insertEnd(val); break;
                    case 3: cin >> key >> val; dll.insertAfter(key,val); break;
                    case 4: cin >> key >> val; dll.insertBefore(key,val); break;
                    case 5: cin >> key; dll.deleteNode(key); break;
                    case 6: cin >> key; dll.search(key); break;
                    case 7: dll.display(); break;
                    case 8: cout << "Size = " << dll.size() << "\n"; break;
                    case 9: cout << (dll.isPalindrome() ? "Yes\n" : "No\n"); break;
                }
            }
        }

        else if (choice == 3) {
            cout << (isCircular(cll.head) ? "It IS circular.\n" : "Not circular.\n");
        }

        else if (choice == 4) break;
    }

    return 0;
}
