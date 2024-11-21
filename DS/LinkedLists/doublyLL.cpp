#include<iostream>
using namespace std;

class DoublyLL{
    private:
    struct Node{
        int val;
        Node* prev;
        Node* next;
    };
    Node * head;
    public:
    DoublyLL(){
        head = nullptr;
    }
    Node* create(int data){
        Node* newNode = new Node;
        newNode->val = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }
    void insertEnd(int data){
        Node* newNode = create(data);
        Node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insert(int data, int pos){
        Node* newNode = create(data);
        Node* temp = head;

        int count = 0;
        while(temp->next!=nullptr && count!=pos){
            temp = temp->next;
            count++;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void del_position(int pos){
        Node* temp = head;
        if(pos == 0){
            head = head->next;
            delete temp;
        }
        int count=0;
        while(temp->next!=nullptr && count<pos){
            temp=temp->next;
            count++;
        }
        if(temp == nullptr){
            cout << "Position out of bounds!" << endl;
        }
        if(temp->next!=nullptr){
            temp->next->prev = temp->prev;
        }
        if(temp->prev!=nullptr){
            temp->prev->next = temp->next;
        }
        delete temp;
    }
    ~DoublyLL(){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
//del_data is much easier to traverse when compared to del_pos, therefore not coded.

};
