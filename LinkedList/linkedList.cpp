#include <iostream>
#include <stdexcept>
using std::cout;
template <typename ListValue>
struct Node {
    Node<ListValue>* next = nullptr;
    Node<ListValue>* prev = nullptr;
    ListValue data;
};
template <typename ListValue>

class LinkedList{
    private:
    Node<ListValue>* head = nullptr;
    Node<ListValue>* tail = nullptr;
    int size = 0;
    public:
    LinkedList(){
    }
    ~LinkedList(){
        if(this->head != nullptr){
            Node<ListValue>* current;
            current = this->head;
            while(current != nullptr){
                Node<ListValue>* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
    void push_back(ListValue val){
        if(this->head == nullptr){
            Node<ListValue>* ptr = new Node<ListValue>;
            ptr->data = val;
            this->head = ptr;
            this->tail = ptr;
            ptr = nullptr;
        }else{
            Node<ListValue>* current = this->head;
            Node<ListValue>* ptr = new Node<ListValue>;
            ptr->data = val;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = ptr;
            ptr->prev = current;
            this->tail = ptr;
        }
        this->size++;
    }
    ListValue pop_back(){
        if(this->head == nullptr){
            throw std::out_of_range("The List is empty");
        }else if(!this->head->next){
            ListValue val = this->head->data;
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            this->size--;
            return val;
        }else{
            // Node<ListValue>* current = this->head;
            // while(current->next != nullptr){
            //     current = current->next;
            // }
            // ListValue val = current->data;
            // current->prev->next = nullptr;
            // delete current;
            // this->size--;
            // return val;
            ListValue val = this->tail->data;
            Node<ListValue>* prev = this->tail->prev;
            delete this->tail;
            this->tail = prev;
            prev->next = nullptr;
            this->size--;
            return val;
        }
    }
    int getSize () const{
        return this->size;
    }
    void print(){
        if(this->head != nullptr){
            Node<ListValue>* current = this->head;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
        }else{
            cout << "No elements";
        }
    }
};
int main(){
    LinkedList<int> list;

    // Test 1: Empty list
    cout << "Size: " << list.getSize() << "\n";
    list.print();
    cout << "\n\n";

    // Test 2: Push elements
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    cout << "Size: " << list.getSize() << "\n";
    list.print();
    cout << "\n\n";

    cout << "Removed: " << list.pop_back() << "\n";
    cout << "Size: " << list.getSize() << "\n";
    list.print();
    cout << "\n\n";

    // Test 3: Pop remaining elements
    cout << "Removed: " << list.pop_back() << "\n";
    cout << "Removed: " << list.pop_back() << "\n";
    cout << "Size: " << list.getSize() << "\n";
    list.print();
    cout << "\n\n";
}


