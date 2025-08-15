#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node 
{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack 
{
    private:
        Node* top;

    public:
        // Constructor
        Stack() : top(nullptr) {}

        // Destructor
        ~Stack() {
            while (!isEmpty()) 
            {
                pop();
            }
        }

        // Push operation
        void push(int element) 
        {
            Node* newNode = new Node(element);
            newNode->next = top;
            top = newNode;
            cout << element << " pushed to stack.\n";
        }

        // Pop operation
        int pop() 
        {
            if (isEmpty()) 
            {
                cout << "Stack Underflow: Cannot pop element, stack is empty.\n";
                return -1; // Or throw an exception
            }
            int poppedData = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            cout << poppedData << " popped from stack.\n";
            return poppedData;
        }

        // Peek/Top operation
        int peek() 
        {
            if (isEmpty()) 
            {
                cout << "Stack is empty.\n";
                return -1; // Or throw an exception
            }
            return top->data;
        }

        // isEmpty operation
        bool isEmpty() 
        {
            return top == nullptr;
        }
};

int main() 
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << std::endl;

    s.pop();
    s.pop();

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << std::endl;

    s.pop(); // Pop the last element
    s.pop(); // This will cause Stack Underflow

    return 0;
}