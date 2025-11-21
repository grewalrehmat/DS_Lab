#include <iostream>
#include <limits.h>
#include <math.h>
#include <algorithm>
class Node{
public:
    int data;
    Node* left;
    Node* right;

    void preorder(Node *temp){
        if(temp == NULL) return;
        std::cout<<temp->data<<std::endl;
        preorder(temp->left);
        preorder(temp->right);
    }

    void inorder(Node *temp){
        if(temp == NULL) return;
        inorder(temp->left);
        std::cout<<temp->data<<std::endl;
        inorder(temp->right);
    }

    void postorder(Node * temp){
        if(temp != NULL){
            preorder(temp->left);
            preorder(temp->right);
            std::cout<<temp->data<<std::endl;
        }
    }

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    // TC is O(h), where h is the height of the tree.
    Node* search1(Node* root, int val){
        if(root->data == val || root == NULL) return root;
        while(root->data != val && root != NULL){
            if(val < root->data) root = root->left;
            else root = root->right;
        }
        return root==NULL?root:NULL;
    }

    Node* search2(Node* root, int val){
        if(root == NULL && root->data == val) return root;
        if (val < root->data) search2(root->left,val);
        else search2(root->right,val);

        return root;
    }

    int minelement(Node* r){
        if(r == NULL) return 0;
        else if(r->left == NULL) return r->data;
        while(r->left != NULL) r = r->left;
        return r->data;
    }

    Node* minelement_node(Node* r){
        if(r == NULL) return r;
        else if(r->left == NULL) return r;
        while(r->left != NULL) r = r->left;
        return r;
    }

    int maxelement(Node* r){
        if(r == NULL) return 0;
        else if(r->right == NULL) return r->data;
        while(r->right != NULL) r = r->right;
        std::cout<<r->data<<std::endl;
        return r->data;
    }

    int succ_without_parent(Node* root,Node* curr){
        if(curr->right != NULL) return minelement(curr->right);
        Node* succ;
        while (true){
            if(curr->data < root->data){
                succ = root;
                root = root->left;
            }
            else if (curr->data > root->data) root = root->right;
            else break;
        }
        std::cout<<succ->data<<std::endl;
        return succ->data;
    }

    int insertion_without_parent(Node* root,int val){
        Node* x = root;
        if(x == NULL) return (-1) * val;

        if(val < root->data) insertion_without_parent(root->left,val);
        else if( val > root->data) insertion_without_parent(root->right,val);
        return val;
    }
    bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
        if (root == nullptr) return true;

        if (root->data <= minVal || root->data >= maxVal)
            return false;

        return isBSTUtil(root->left, minVal, root->data) &&
            isBSTUtil(root->right, root->data, maxVal);
    }

    Node* deletion_without_parent(Node* root, int val) {
        if (root == NULL) return NULL;
        if (val < root->data)  root->left = deletion_without_parent(root->left, val);
        else if (val > root->data) root->right = deletion_without_parent(root->right, val);

        else { //if there is only 1 children
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            //If we have 2 children 

            Node* temp = minelement_node(root->right); //Finding successor Node
            root->data = temp->data; //Copy the successor node's data in the current node
            root->right = deletion_without_parent(root->right, temp->data); //Delete the successive Node.
        }

        return root;
    }

    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }

    int minDepth(Node* root) {
        if (root == nullptr)
            return 0;

        // leaf node
        if (!root->left && !root->right)
            return 1;

        // left child is NULL go right
        if (!root->left)
            return 1 + minDepth(root->right);

        // right child is NULL
        if (!root->right)
            return 1 + minDepth(root->left);

        // Both children exist
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }



};

int main(){
    Node* bt = new Node(5);
    bt ->right = new Node(8);
    bt-> right->left = new Node(6);
    bt->right->right = new Node(9);

    bt->left = new Node(3);
    bt->left->left = new Node(2);
    bt->left->right = new Node(4);
    bt->left->left->left = new Node(1);
    
    std::cout<<"Inorder Traversal" <<std::endl;
    bt->inorder(bt);

    std::cout<<"Postorder Traversal"<<std::endl;
    bt->postorder(bt);

    std::cout<<"Preorder Traversal"<<std::endl;
    bt->preorder(bt);

    std::cout<<"Maximum Elements" <<std::endl;
    bt->maxelement(bt);

    std::cout<<"Successor of " << bt->left->left->left ->data <<std::endl;
    bt->succ_without_parent(bt,bt->left->left->left);

}
