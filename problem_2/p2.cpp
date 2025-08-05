#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    void init(int value) {
        data = value;
        next = nullptr;
    }
};
class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
    void init() {
        head = nullptr;
    }
    void add(Node* newNode) {
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    LinkedList operator+(const LinkedList& other) {
        LinkedList result;
        int carry = 0;
        Node* temp1 = this->head;
        Node* temp2 = other.head;
        while (temp1 != nullptr || temp2 != nullptr) {
            if(temp1 != nullptr && temp2 != nullptr) {
                carry += temp1->data + temp2->data;
            } else if(temp1 != nullptr) {
                carry += temp1->data;
            } else if(temp2 != nullptr) {
                carry += temp2->data;
            }
            Node* newNode = new Node();
            newNode->init(carry % 10);
            result.add(newNode);
            carry /= 10;
            if(temp1 != nullptr) temp1 = temp1->next;
            if(temp2 != nullptr) temp2 = temp2->next;
        }
        if (carry > 0) {
            Node* newNode = new Node();
            newNode->init(carry);
            result.add(newNode);
        }
        return result;
    }
    void print() {
        Node* temp = head;
        cout << "[";
        while (temp->next != nullptr) {
            cout << temp->data << ",";
            temp = temp->next;
        }
        cout << temp->data << "]";
        cout << endl;
    }
};
int main() {
    int l1,l2;
    cout << "Enter first list length: ";
    cin >> l1;
    LinkedList list1;
    list1.init();
    for(int i = 0; i < l1; i++) {
        Node* newNode = new Node();
        int value;
        cout << "Enter number at position " << i << " of list 1: ";
        cin >> value;
        newNode->init(value);
        list1.add(newNode);
    }
    cout << endl;
    cout << "Enter second list length: ";
    cin >> l2;
    LinkedList list2;
    list2.init();
    for(int i = 0; i < l2; i++) {
        Node* newNode = new Node();
        int value;
        cout << "Enter number at position " << i << " of list 2: ";
        cin >> value;
        newNode->init(value);
        list2.add(newNode);
    }
    LinkedList result = list1 + list2;
    cout << endl;
    cout << "List 1: ";
    list1.print();
    cout << "List 2: ";
    list2.print();
    cout << "Resulting list: ";
    result.print();
    return 0;
}