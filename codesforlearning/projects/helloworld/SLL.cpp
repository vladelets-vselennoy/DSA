
#include<iostream>
using namespace std;
class SLL {
private:
    struct node {
        int data;
        node* next;
    };
    node* head =nullptr;
    node* tail =nullptr ;
public:
    SLL(){
       head=tail=nullptr;}
    void Pushfront(int data) {

        node* temp = new node;
        temp->data = data;
        temp->next = head;
        head = temp;
        if (tail == NULL) {
            tail = temp;
        }
    }
    void Topfront() {
        if (head == NULL) {
            cout << "Empty List" << endl;
        }
        else {
            cout << head->data << endl;

        }
    }
    int Popfront() {
        if (head == NULL) {
            cout << "Empty list" << endl;
            return 0;
        }
        else {
            node* temp = head;
            int data = head->data;
            head = head->next;
            delete temp;
            return data;
        }
    }
    void Pushback(int data) {
        node* temp = new node;
        temp->data = data;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;

        }

    }
    void Topback() {
        if (head == NULL) {
            cout << "Empty List" << endl;
        }
        else {
            cout << tail->data << endl;
        }

    }
    int Popback() {
        if (tail == NULL) {
            cout << "Ëmpty List" << endl;
        }
        else {
            node* temp = tail;
            int data = tail->data;
            node* temp1 = head;
            while (temp1->next != tail) {
                temp1 = temp1->next;
            }
            tail = temp1;
            tail->next = NULL;
            delete temp;
            return data;
        }
        return 0;

    }
    bool Find(int data) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;

        }
        return false;
    }
    bool Empty() {
        if (head == NULL) {
            return true;
        }
        else {
            return false;

        }
    }
    void Erase(int data) {
        if (head = NULL) {
            cout << "Empty List" << endl;
        }
        else {
            node* temp = head;
            node* temp1 = head;
            while (temp->data != data) {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = temp->next;
            delete temp;

        }

    }
    void Addbefore(int data, int before) {
        if (head == NULL) {
            cout << "Empty List" << endl;
        }
        else {
            node* temp = head;
            node* temp1 = head;
            while (temp->data != before) {
                temp1 = temp;
                temp = temp->next;
            }
            node* temp3 = NULL;
            temp3->data = data;
            temp3->next = temp;
            temp1->next = temp;
            delete temp3;
            delete temp1;
            delete temp;
        }
    }

};



int main() {
    SLL myList;

    // Test Pushfront
    myList.Pushfront(10);
    myList.Pushfront(20);
    myList.Pushfront(30);

    // Test Topfront
    myList.Topfront();
    cout << "Topfront: " << endl;

    // Test Popfront
    cout << "Popfront: " << myList.Popfront() << endl;

    // Test Pushback
    myList.Pushback(40);
    myList.Pushback(50);

    // Test Topback
    myList.Topback();
    cout << "Topback: " << endl;

    // Test Popback
    cout << "Popback: " << myList.Popback() << endl;

    // Test Find
    cout << "Find 20: " << (myList.Find(20) ? "Found" : "Not Found") << endl;

    // Test Empty
    cout << "Is the list empty? " << (myList.Empty() ? "Yes" : "No") << endl;

    // Test Erase
    myList.Erase(20);

    // Test Addbefore
    myList.Addbefore(35, 40);

    // Print the modified list
    cout << "Modified List: ";
    while (!myList.Empty()) {
        cout << myList.Popfront() << " ";
    }

    return 0;
}
