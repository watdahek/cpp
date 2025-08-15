/*
std::shared_ptr : Shared Ownership

shared_ptr allows multiple smart pointers to own the same dynamically allocated object. 
Internally, it maintains a reference count. Each time a shared_ptr is copied, the count is incremented. 
When the last shared_ptr referencing the object is destroyed or reset, the object is automatically deallocated.

This makes shared_ptr ideal for cases where ownership is shared across different parts of the code 
— for example, when passing objects between layers or storing shared resources in containers. 
However, this flexibility comes at a cost. shared_ptr is heavier than unique_ptr because of the reference counting mechanism, 
and it may introduce circular reference issues in cases where two shared_ptrs are referencing each other, 
which can lead to memory leaks if not handled carefully.

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
            cout << "shared pointer used here\n";
        }
};

int main() 
{
    // Creating a unique pointer of type 'Demo'
    shared_ptr<Demo> ptr1 = make_shared<Demo>();
    cout << "Address of ptr1: " << &ptr1 << "\n";
    ptr1->display();
    cout << "Current reference count of ptr1 is: " << ptr1.use_count() << "\n";
    {
        // Sharing ownership with anothr pointer
        shared_ptr<Demo> ptr2 = ptr1;
        cout << "Address of ptr2: " << &ptr2 << "\n";
        cout << "Current reference count of ptr2 is: " << ptr2.use_count() << "\n";  
        cout << "Current reference count of ptr1 is: " << ptr1.use_count() << "\n";  
        ptr2->display();    
    } // // Scope for ptr2 ends here, ref count would reduce

    cout << "Current reference count of ptr1 is: " << ptr1.use_count() << "\n"; 
    return 0;
}
