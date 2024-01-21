#include<iostream>
using namespace std;
class SLL{
    private:
    struct node {
        node * next;
        int data;

    };
    node * head=nullptr;
    node * tail=nullptr;
    public:
    SLL(){
        head=tail=nullptr;        
    }
    void PushFront(int data){
        // if (head==nullptr){
        //     node * temp= new node;
        //     temp->next=nullptr;
        //     temp->data=data;
        //     head=temp;
        // }
        node *temp=new node;
        temp->data=data;
        temp->next=head;
        head=temp;
        if (tail==nullptr){
            tail=temp;
        }
    }
    void TopFront(){
        if (head==NULL)
{
      cout<<"empty linkedist"<<endl;

    }
    else{
        cout<<head->data<<endl;
    }


}
    int PopFront(){
        int k;
        if(head==NULL){
            cout<<"empty linkedlist"<<endl;
            // return;
        }
        else if(head==tail){
            k=head->data;
            head=tail=NULL;
            return k;
        }
        else{
            k=head->data;
            head=head->next;
            return k;
        }
    }
    void PushBack(int data){
        node * temp=new node;
        temp->next=nullptr;
        temp->data=data;
        if(head==NULL){
            head=tail=temp;

        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    void TopBack(){
        // int k;
        if(tail==NULL){
            cout<<"empty list"<<endl;

        }
        else{
            cout<< tail->data<<endl;
        }
      
    }
    int PopBack(){
        int k;
        if(head==NULL){
            cout<<"empty linked list"<<endl;
            // return -1;
        }
        else if(head ==tail){
            k=head->data;
            head=tail=nullptr;
            return k;
        }
        else{
            k=tail->data;
            node * temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            tail=temp;
            tail->next=nullptr;
            return k;

        }

    }
    bool Find(int data){
        node * temp=head;
        while(temp!=NULL){
            if (temp->data==data){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    void Erase(int data){
        node *temp=head;
        bool k=Find(data);
        if (!k){
            cout<<"data doesn't exist"<<endl;

        }
        else if(head->data==data)
        PopFront();
        else if (tail->data==data)
        PopBack();
        else{
            while(temp->next->data!=data){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            cout<<"successfully erased"<<endl;
        }

        }
    bool Empty(){
        return (head==tail && tail==NULL);
    }
    void AddBefore(node * n,int data){
        node * temp=head;
        node * temp2=new node;
        temp2->next=n;
        temp2->data=data;
        if (head==NULL){
            cout<<"empty linked lsit"<<endl;
        }
        else if (head==n){
            PushFront(data);}
        else{
            while(temp->next!=n){
                temp=temp->next;
            }
            temp->next=temp2;

        }        
    }
    void AddAfter(node * n, int data){
        if(head==NULL){
            cout<<"empty linkedlsit"<<endl;
        }
        else if(tail==n)
        PushBack(data);
        else{
            node * temp= new node;
            temp->next=n->next;
            temp->data=data;
            n->next=temp;
        }

    }


    


};
int main() {
    SLL myList;

    // Test Pushfront
    myList.PushFront(10);
  
    myList.PushFront(20);
    myList.PushFront(30);
    cout<<myList.PopFront()<<"ok"<<endl;

    // Test Topfront
    myList.TopFront();
    cout << "Topfront: " << endl;

    // Test Popfront
    cout << "Popfront: " << myList.PopFront() << endl;

    // Test Pushback
    myList.PushBack(40);
    myList.PushBack(50);

    // Test Topback
    myList.TopBack();
    cout << "Topback: " << endl;

    // Test Popback
    cout << "Popback: " << myList.PopBack() << endl;

    // Test Find
    cout << "Find 20: " << (myList.Find(20) ? "Found" : "Not Found") << endl;

    // Test Empty
    cout << "Is the list empty? " << (myList.Empty() ? "Yes" : "No") << endl;

    // Test Erase
    myList.Erase(20);

    // Test Addbefore
    // myList.AddBefore(35, 40);

    // Print the modified list
    cout << "Modified List: ";
    while (!myList.Empty()) {
        cout << myList.PopFront() << " ";
    }

    return 0;
}

