#include <iostream>

using namespace std;

// Array-based stack implementation
// Define class Stack
class Stack
{
    private:
        int *arr;
        int top = 0;
        int capacity = 0;

    public:
        // Constructor
        Stack(int capa)
        {
            capacity = capa;
            arr = new int[capacity];
            top = -1;   // intialize top to -1 for an empty stack
            cout << "New stack created, capacity = " << capa << " \n";
        }

        // Destructor
        ~Stack()
        {
            delete[] arr;
        }

        // Push operation: add an element to the top of the stachk
        void push(int element)
        {
            if (top == capacity - 1)
            {
                cout << "Stack is full, cannot push element !!!\n";
                return;        
            }    
            arr[++top] = element;
            cout << element << " pushed to stack.\n";
        }

        // Pop operation: remove and return the top element
        int pop ()
        {
            int poppedElement = 0;

            if (top == -1)
            {
                cout << "Stack is empty, cannot pop element!!!\n";
                return -1;  // or throw an exception    
            }
            poppedElement = arr[top--];
            cout << poppedElement << " popped from stack.\n";
            return poppedElement;    
        }

        // Peek/Top operation: return the top element without removing it
        int peek()
        {
            if (top == -1)
            {
                cout << "Stack is empty!!!\n";
                return -1;  // or throw an exception    
            }
            return arr[top];
        }

        // isEmpty opertion: check if the stack is empty
        bool isEmpty()
        {
            return top == -1;
        }

        // isFull: check if the stack is full
        bool isfull()
        {
            return top == capacity - 1;
        }
};

int main()
{
    int stack_capacity = 5;
    
    // Create a stack
    Stack stack_s(stack_capacity);
    stack_s.push(10);
    stack_s.push(20);
    stack_s.push(30);

    cout << "Top element: " << stack_s.peek() << " \n";

    stack_s.pop();
    stack_s.pop();

    cout << "Is stack empty? " << (stack_s.isEmpty() ? "Yes\n" : "No\n");

    stack_s.push(40);
    stack_s.push(50);
    stack_s.push(60);
    stack_s.push(70);
    stack_s.push(80);

    return 0;
}