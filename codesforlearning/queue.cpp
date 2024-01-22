#include<iostream>
class Queue{
    private:
    static const int MAX_SIZE=10;
    int arr[MAX_SIZE];
    int r=-1,w=0;       
    public:
    void Enqueue(int data){
        if (r==-1 ){
             r=0;
             arr[w]=data;
             w+=1;
        }
        else if(r>w && r-w>=2){
           arr[w]=data;
           w+=1;

        }
        else if (w>r || w==r){
            arr[w]=data;
            if(w==MAX_SIZE-1)
            {
                if(r!=0)
                w=-1;
                else
                w=0;

            }
            w+=1;
        }
        else
        std::cout<<"overflow"<<std::endl;
    }
    void Dequeue(){
        if(r==-1 || r==w)
        std::cout<<"underflow"<<std::endl;
        else if (w==-1 && r==0){
            w=0;
            r+=1;
        }
        else if(r==MAX_SIZE-1){
            r=0;
        }
        else
        r+=1;
    }
    bool Empty(){
        return (r==w);
    }
    int Front(){
        return arr[r];
    }

};
int main() {
    Queue myQueue;

    // Enqueue elements
    myQueue.Enqueue(10);
    myQueue.Enqueue(20);
    myQueue.Enqueue(30);
    myQueue.Enqueue(40);
    myQueue.Enqueue(50);

    // Display the queue
    std::cout << "Queue elements after enqueue: ";
    while (!myQueue.Empty()) {
        std::cout << myQueue.Front() << " ";
        myQueue.Dequeue();
    }
    std::cout << std::endl;

    // Try dequeue when the queue is empty
    myQueue.Dequeue(); // This should print "underflow"

    // Enqueue more elements
    myQueue.Enqueue(60);
    myQueue.Enqueue(70);

    // Display the queue
    std::cout << "Queue elements after enqueue: ";
    while (!myQueue.Empty()) {
        std::cout << myQueue.Front() << " ";
        myQueue.Dequeue();
    }
    std::cout << std::endl;

    return 0;
}