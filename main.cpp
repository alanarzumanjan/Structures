#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public: 
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void ListDisplay() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    void ReverseList() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void SortAddr() {
        if (head == nullptr || head->next == nullptr)
        return;

        bool swapped;
        Node* temp;

        do {
            swapped = false;
            Node* current = head;
            Node* prev = nullptr;

            while (current->next != nullptr) {
                if (current > current->next) { 
                    if (prev != nullptr) {
                        prev->next = current->next;
                    } else {
                        head = current->next;
                    }
                    
                    temp = current->next->next;
                    current->next->next = current;
                    current->next = temp;

                    swapped = true;
                }

                prev = current;
                current = current->next;
            }
        } while (swapped);
    }

};

void PrintAddresses(const LinkedList& list) {
    Node* current = list.head;
    while (current != nullptr){
        cout << current << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    
    cout << "List: ";
    list.ListDisplay();
    
    cout << "Reverse List: ";
    list.ReverseList();
    list.ListDisplay();

    cout << "Addr:" << endl;
    PrintAddresses(list);
    
    cout << "Sorting addr:" << endl;
    list.SortAddr();
    PrintAddresses(list);
    
    return 0;
}
