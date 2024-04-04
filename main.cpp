#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    int len = 0;

    LinkedList()
    {
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

    void sort()
    {
        Node *prev_node = nullptr;
        Node *current_node = head;
        Node *next_node = current_node->next;
        Node *new_head = head;
        Node *min_node = head;
        Node *before_min = prev_node;
        Node *after_min = next_node;
        Node *unsorted_starts_here = head;
        Node *sorted_ends_here = nullptr;

        while (true)
        {
            current_node = unsorted_starts_here;
            while (current_node != nullptr)
            {
                if (current_node->data <= min_node->data)
                {
                    before_min = prev_node;
                    min_node = current_node;
                    after_min = next_node;
                }

                prev_node = current_node;
                current_node = current_node->next;

                if (current_node != nullptr)
                    next_node = current_node->next;
            }

            if (min_node == unsorted_starts_here)
            {
                unsorted_starts_here = unsorted_starts_here->next;
            }

            min_node->next = new_head;
            if (sorted_ends_here == nullptr)
            {
                sorted_ends_here = min_node;
            }
            new_head = min_node;
            before_min->next = after_min;
            min_node = unsorted_starts_here;

            if (min_node == nullptr)
            {
                break;
            }

            next_node = unsorted_starts_here->next;
            prev_node = sorted_ends_here;
        }
        head = new_head;
    }
};

int main()
{
    LinkedList list;

    list.append(1);
    list.append(4);
    list.append(0);
    list.append(-30);
    list.append(2);
    list.append(14);
    list.append(5);
    list.append(-12);

    cout << "List: ";
    list.ListDisplay();

    cout << "Reverse List: ";
    list.ReverseList(); list.ListDisplay();

    cout << "Sorted List: ";
    list.sort(); list.ListDisplay();

    return 0;
}