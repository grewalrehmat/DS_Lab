#include <iostream>

using namespace std;

class Node{
public:
    int val; Node *next;

   Node(int v) {
        val = v; 
        next = nullptr;
   }
   Node(){}
};

class LL{
    Node* head;
public:
    LL(){
        head=nullptr;
    }

    bool search (int x);

    void disp() const;

    void insertbegin();

    void insertend();

    void insertposi(int p,int elem);

    void delsl();

    void reversal(Node* head){
        if(head == NULL) return;
        reversal(head->next);
        cout<<head->val<<endl;
    }

    Node* middleOfLL(Node* head){
        if(head == NULL) return nullptr;
        Node* fast = head; 
        Node* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    int countAndDelete(Node*& head, int key) {
        int count = 0;

        while (head && head->val == key) {
            Node* del = head;
            head = head->next;
            delete del;
            count++;
        }

        if (!head) return count;     

        Node* curr = head;
        while (curr->next) {
            if (curr->next->val == key) {
                Node* del = curr->next;
                curr->next = curr->next->next;
                delete del;
                count++;
            } else {
                curr = curr->next;
            }
        }

        return count;
    }
    void display(Node* head) {
        while (head) {
            cout << head->val;
            if (head->next) cout << "->";
            head = head->next;
        }
        cout << endl;
    }

    Node* delbeg(Node* head){
        if(!head) return nullptr;
        Node* curr = head;
        head = head->next;
        delete curr;
        return head;
    }

    bool deleteSpecific(Node*& head, int key) {
        if (!head) return false;
        if (head->val == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* curr = head;
        while (curr->next) {
            if (curr->next->val == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    int searchNode(Node* head, int key) {
        int pos = 1;
        while (head) {
            if (head->val == key) return pos;
            head = head->next;
            pos++;
        }
        cout<<"Not Found"<<endl;
        return -1;
    }

};

bool LL::search(int x){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->val == x) return true;
        temp=temp->next;
    }
    return false;
}

void LL::disp() const{
    Node* curr = head;
    while(curr!= nullptr){
        cout<<curr->val<<endl;
        curr=curr->next;
    }
}

void LL::insertbegin(){
    Node *curr = new Node(5);
    curr->next = head;
    head = curr;

}


void LL::insertend(){
    Node *curr = new Node(4);
    Node *temp;
    while(temp->next != nullptr){
        temp->next = temp;
    }
    temp->next=curr;
}

void LL::insertposi(int p,int elem){
    Node* temp = head;
    if(p==0 && head!= nullptr){
        head = temp->next;
        delete temp;
    }
    else{
        int cposi = 0;
        Node* curr = head;
        while(curr->next != nullptr && cposi < p - 1){
            curr=curr->next;
            cposi++;
        }
        if(curr->next == nullptr) cout<<"Invalid range";
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

    }
}

void LL::delsl(){
    Node* curr = head;
    if(head==NULL) return;
    else{
        while(curr->next->next != nullptr){
            curr=curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
    }
}