#include<iostream>
using namespace std;

class BST{
    private:
    struct Node{
        int val;
        Node* right;
        Node* left;
    };
    Node* root;
    
    Node* create(int data){
        Node* newNode = new Node;
        newNode->val = data;
        newNode->right = newNode->left = nullptr;
        return newNode;
    }

    Node* insert(Node* root, int data){
        if(root == nullptr){
            return create(data);
        }

        if(data < root->val){
            root->left = insert(root->left, data); //It'll keep going left till it hits a node with a nullptr
        }else {
            root->right = insert(root->right, data);
        }
        return root;
    }
    void preOrder(Node* root){
        if(root!=nullptr){
            cout << root->val << endl;
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void inOrder(Node* root){
        if(root!=nullptr){
            inOrder(root->left);
            cout << root->val << endl;
            inOrder(root->right);
        }
    }

    void postOrder(Node* root){
        if (root!= nullptr){
            postOrder(root->left);
            postOrder(root->right);
            cout << root->val << endl;
        }
    }
    void deleteTree(Node* root) {
        if (root != nullptr) {
            deleteTree(root->left);  
            deleteTree(root->right); 
            delete root;  
        }
    }
//All of the above functions are recursive. It'll keep calling in on itself until it reaches the leaf, and perform traversal operations accordingly.
    public:
    BST(){
        root = nullptr;
    }
    ~BST(){
        deleteTree(root);
    }
    void insert(int val){
        insert(root, val);
    }
    
    void printPreOrder() {
        preOrder(root);
        cout << endl;
    }

    void printInOrder() {
        inOrder(root);
        cout << endl;
    }

    void printPostOrder() {
        postOrder(root);
        cout << endl;
    }

};