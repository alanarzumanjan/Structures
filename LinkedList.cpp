#include <iostream>
using namespace std;
// make
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

    void append(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void ListDisplay()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void ReverseList()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr)
        {
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

class Stack : public LinkedList
{
public:
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            len++;
            return;
        }
        newNode->next = head;
        head = newNode;
        len++;
    }

    int pop()
    {
        int ret_val = head->data;

        head = head->next;
        len--;
        return ret_val;
    }

    int peek()
    {
        int ret_val = head->data;
        return ret_val;
    }

    bool is_empty()
    {
        return head == nullptr;
    }

    int size()
    {
        int count = 0;
        Node *current = head;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    bool Valid(string data)
    {
        Stack your_mama;

        for (char bracket : data)
        {
            if (bracket == '(' || bracket == '[' || bracket == '{')
            {
                your_mama.push(bracket);
            }
            else if (bracket == ')' || bracket == ']' || bracket == '}')
            {
                if (your_mama.is_empty())
                {
                    return false;
                }
                char top = your_mama.peek();
                if ((bracket == ')' && top == '(') ||
                    (bracket == ']' && top == '[') ||
                    (bracket == '}' && top == '{'))
                {
                    your_mama.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return your_mama.is_empty();
    }
};
 
void deleteStack(Stack &stack)
{
    Node *current = stack.head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    stack.head = nullptr;
    stack.len = 0;
}

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
    list.ReverseList();
    list.ListDisplay();

    cout << "Sorted List: ";
    list.sort();
    list.ListDisplay();

    Stack stack;
    cout << "Not push - Size: " << stack.size() << endl;
    stack.push(1);
    stack.push(4);
    stack.push(0);
    stack.push(-30);
    stack.push(2);
    stack.push(14);
    stack.push(5);
    stack.push(-12);

    cout << "Push - Size: " << stack.size() << endl;

    printf("top: %d\n", stack.peek());
    printf("pop: %d\n", stack.pop());
    printf("pop: %d\n", stack.pop());

    printf("top: %d\n", stack.peek());
    printf("top: %d\n", stack.peek());
    printf("top: %d\n", stack.peek());
    printf("top: %d\n", stack.peek());

    printf("pop: %d\n", stack.pop());
    printf("pop: %d\n", stack.pop());
    printf("pop: %d\n", stack.pop());

    if (stack.is_empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    cout << "Before all - Size: " << stack.size() << endl;

    deleteStack(stack);

    cout << "After deletion - Size: " << stack.size() << endl;
    if (stack.is_empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    string mark;
    cout << "Enter Brackets: ";
    cin >> mark;
    if (stack.Valid(mark))
    {
        printf("Valid Brackets\n");
    }
    else
    {
        cout << "Not Valid Brackets!\n";
    }
    return 0;
}