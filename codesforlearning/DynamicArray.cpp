#include<iostream>
class DynamicArray{
    private:
    int *a;
    int *ptr;
    int size;
    int capacity;

    public :
    DynamicArray(){
        a=new int[1];
        size=0;
        capacity=1;

    }
    void PushBack(int data){
        if (size==capacity){
            int *DA=new int[capacity*2];
            capacity*=2;
            for(int i=0;i<size;i++){
                DA[i]=a[i];
            }
            ptr=a;
            a=DA;
            delete [] ptr;
        
        }
        a[size]=data;
        size+=1;
    }
    void Get(int i){
        std::cout<<a[i]<<" "        ;

    }
    void Set(int i , int val){
        a[i]=val;
    }
    void Remove(int i){
        for(int k=i;k<size-1;k++){
            a[k]=a[k+1];
            size-=1;
        }
    }
    void Dsiplay(){
        std::cout<<"Elements in the dynamic array";
        for(int i=0;i<size;i++){
            std::cout<<a[i]<< " ";

        }
        std::cout<<std::endl;
    }



};


int main() {
    DynamicArray dynamicArray;

    // Push some elements to the array
    dynamicArray.PushBack(10);
    dynamicArray.PushBack(20);
    dynamicArray.PushBack(30);
    dynamicArray.PushBack(40);

    // Display the elements in the array
    dynamicArray.Dsiplay();

    // Get and display an element
    dynamicArray.Get(2); // Expected output: 30

    // Set and display the modified array
    dynamicArray.Set(1, 25);
    dynamicArray.Dsiplay(); // Expected output: 10 25 30 40

    // Remove an element and display the modified array
    dynamicArray.Remove(2);
    dynamicArray.Dsiplay(); // Expected output: 10 25 40

    return 0;
}