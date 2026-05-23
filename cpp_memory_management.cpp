// C++: Memory Management - Manual Memory Management Demo
#include <iostream>
#include <string>
using namespace std;

// Simple class to track allocation and deallocation
class MemoryBlock {
public:
    string name;
    int* data;
    int size;
    
    MemoryBlock(string n, int s) {
        name = n;
        size = s;
        data = new int[s];   // allocate array on heap
        cout << "ALLOCATED: " << name << " (" << s << " integers)" << endl;
    }
    
    ~MemoryBlock() {
        delete[] data;       // must manually free array
        cout << "FREED:     " << name << endl;
    }
};

void properMemoryManagement() {
    cout << "=== PROPER MEMORY MANAGEMENT ===" << endl;
    
    // Allocate single value on heap
    int* ptr = new int(42);
    cout << "Allocated integer: " << *ptr << endl;
    
    delete ptr;          // manually free memory
    ptr = nullptr;       // prevent dangling pointer
    cout << "Freed integer, pointer set to nullptr" << endl;
    
    // Allocate array on heap
    int* arr = new int[5]{10, 20, 30, 40, 50};
    cout << "\nAllocated array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;        // must use delete[] for arrays
    arr = nullptr;
    cout << "Freed array with delete[]" << endl;
}

void danglingPointerDemo() {
    cout << "\n=== DANGLING POINTER DEMO ===" << endl;
    
    int* ptr = new int(99);
    cout << "Value before delete: " << *ptr << endl;
    
    delete ptr;          // memory freed
    ptr = nullptr;       // safe — set to nullptr immediately
    
    if (ptr == nullptr) {
        cout << "Pointer is nullptr — safe to check before use" << endl;
    }
    // Without setting to nullptr, accessing ptr after delete
    // causes undefined behavior — a common C++ bug
}

void memoryLeakDemo() {
    cout << "\n=== MEMORY LEAK DEMO ===" << endl;
    
    // This block allocates but NEVER frees
    int* leaky = new int(55);
    cout << "Allocated leaky pointer: " << *leaky << endl;
    cout << "WARNING: No delete called — this is a memory leak!" << endl;
    // delete leaky; // if this line is commented out = memory leak
    // The OS reclaims it when the program exits, but in long-running
    // programs this accumulates and causes crashes
}

int main() {
    properMemoryManagement();
    
    cout << "\n=== OBJECT MEMORY MANAGEMENT ===" << endl;
    {
        MemoryBlock block1("Block-1", 100);
        MemoryBlock block2("Block-2", 200);
        cout << "Both blocks in use" << endl;
    } // destructor called automatically here for stack objects
    cout << "Both blocks freed (went out of scope)" << endl;
    
    // Heap-allocated objects need explicit delete
    cout << "\n=== HEAP OBJECT MANAGEMENT ===" << endl;
    MemoryBlock* heapBlock = new MemoryBlock("HeapBlock", 50);
    cout << "HeapBlock in use" << endl;
    delete heapBlock;    // must manually call delete
    heapBlock = nullptr;
    
    danglingPointerDemo();
    memoryLeakDemo();
    
    cout << "\n=== SUMMARY ===" << endl;
    cout << "C++ requires developer to manage every allocation" << endl;
    cout << "new  = allocate | delete  = free single object" << endl;
    cout << "new[] = allocate | delete[] = free array" << endl;
    cout << "Forgetting delete = memory leak" << endl;
    cout << "Using pointer after delete = undefined behavior" << endl;
    
    return 0;
}