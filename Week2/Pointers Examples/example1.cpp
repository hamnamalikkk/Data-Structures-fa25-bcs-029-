#include <iostream>
using namespace std;

int* getPointer() {
    int x = 19;
    
    // returning address of local variable
    return &x; 
}

int main() {
    
    // ptr becomes dangling here
    int* ptr = getPointer(); 
    
    
    cout<<*ptr;
    return 0;
}