/*
std::unique_ptr : Exclusive Ownership

unique_ptr is the simplest and most efficient smart pointer in C++. 
It enforces exclusive ownership, meaning only one unique_ptr instance can own a given object at any time. 
Once it goes out of scope, the memory it points to is automatically deallocated. 
This eliminates the need for manual delete calls and prevents memory leaks caused by forgetting to free memory.

You cannot copy a unique_ptr, which avoids accidental sharing and ownership confusion. 
However, you can transfer ownership by using std::move, which moves the resource from one unique_ptr to another. 
This is particularly useful in situations where you want to return a dynamically allocated resource from a function without copying it.

Use unique_ptr as your default choice when dynamic memory is needed, but there's only a single owner.

Reference: https://medium.com/@rithvikseth11/c-memory-management-simplified-47c58af2126c
*/

#include <iostream>
#include <memory>
using namespace std;

class Demo
{
    public:
        Demo(){cout << "Demo object created\n";}
        ~Demo(){cout << "Demo object detroyed\n";}

        void display() const
        {
            cout << "unique pointer used here\n";
        }
};

int main() 
{
    // Creating a unique pointer of type 'Demo'
    unique_ptr<Demo> ptr1 = make_unique<Demo>();
    cout << "Address of ptr1: " << &ptr1 << "\n";
    ptr1->display();

    // Transfer the ownership to anothe unique pointer
    unique_ptr<Demo> ptr2 = move(ptr1);
    cout << "Address of ptr2: " << &ptr2 << "\n";
    cout << "Address of ptr1 after transferring ownership: " << &ptr1 << "\n";
    if(!ptr1)
    {
        cout << "Ownership has been transferred to ptr2\n";
    }
    ptr2->display();

    ptr1->display();
    
    return 0;
}
