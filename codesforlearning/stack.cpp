#include<iostream>
using namespace std;
class Stack{
    private:
    static const int MAX_SIZE=100;
    int arr[MAX_SIZE];
    int top=-1;
    public:
    bool Empty(){
        if (top==-1)
        return true;
        return false;

    }
    void Push(int data){
        if (top==MAX_SIZE-1)
        {cout<<"stack overflow"<<endl;
        return;}
        
        top+=1;
        arr[top]=data;

    }
    int Pop(){
        if (top==-1)
        {cout<<"stack underflow" <<endl;
        return -1000;}
        // cout<<arr[top]<<endl;
        top-=1;
        return arr[top+1];

    }
    void Top(){
        cout<<arr[top]<<endl;
    }
};
using namespace std;
int main() {
    Stack myStack;

    // Push elements onto the stack
    myStack.Push(10);
    myStack.Push(20);
    myStack.Push(30);

    // Pop elements from the stack
    cout << "Popped: " << myStack.Pop() << endl;
    cout << "Popped: " << myStack.Pop() << endl;

    // Check if the stack is empty
    cout << "Is the stack empty? " << (myStack.Empty() ? "Yes" : "No") << endl;

    // Pop from an empty stack
    cout << "Popped: " << myStack.Pop() << endl;
    cout<<myStack.Pop();

    return 0;
}
