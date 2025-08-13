#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class LinkedList {
public:
    ListNode *head;
    ListNode *tail;
    LinkedList() : head(nullptr), tail(nullptr) {}
    void insert(int value) {
        ListNode *newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};
class Solution {
public:
    int Inital = 1;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int *Arr = new int[Inital];
        int count=0;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* current = lists[i];
            while (current != nullptr) {
                Arr[count++] = current->val;
                current = current->next;
                if(count == Inital) {
                    int* newArr = new int[Inital * 2];
                    for (int j = 0; j < Inital; j++) {
                        newArr[j] = Arr[j];
                    }
                    delete[] Arr;
                    Arr = newArr;
                    Inital *= 2;
                }
            }
        }
        sort(Arr, Arr + count);
        ListNode* result = nullptr;
        for(int i=count-1; i>=0; i--) {
            ListNode* newNode = new ListNode(Arr[i]);
            newNode->next = result;
            result = newNode;
        }
        delete[] Arr;
        return result;
    }
    bool CheckNull(ListNode** Arr, int size) {
        for (int i = 0; i < size; i++) {
            if (Arr[i] != nullptr) return false;
        }
        return true;
    }
};
int main(){
    int n;
    cout << "Enter number of linked lists: ";
    cin >> n;
    vector<ListNode*> lists(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter number of elements for linked list " << i + 1 << ": ";
        int numElements;
        cin >> numElements;
        LinkedList ll;
        cout << "Enter values for linked list " << i + 1 << ": ";
        for (int j = 0; j < numElements; j++) {
            int value;
            cin >> value;
            ll.insert(value);
        }
        lists[i] = ll.head;
    }
    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);
    cout << "Merged linked list: ";
    while (merged != nullptr) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
    return 0;
}