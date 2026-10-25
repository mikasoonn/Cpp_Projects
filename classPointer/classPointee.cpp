#include <iostream>
using std::cout;
using std::cin;

class Pointer {
    private: 
    int *ptr = nullptr;
    public:
    Pointer(int num){
        cout << "Number constructor was called for " << num << " value"<< "\n";
        ptr = new int(num);
        if(ptr == nullptr){
            exit(1);
        }
    }
    Pointer(int *pt){
        cout << "Pointer constructor was called for " << *pt << " pointers value" << "\n";
        ptr = pt;
    }
    ~Pointer(){
        delete ptr;
        ptr = nullptr;
    }
    int getVal(){
        return *ptr;
    }
    void setVal(int num){
        *ptr = num;
    }
    void printAddress(){
        cout << "This is your value's address: "<< ptr << "\n";
    }
    void reset(){
        //resets the memory and transfers the value
        int temp = *ptr;
        delete ptr;
        ptr = nullptr;
        ptr = new int(temp);
        cout << "New memory was allocated, the new address is: "<< ptr << "\n";
    }

};
int main(){
    Pointer ob(20);

    int *p = new int(24);
    Pointer ob1(p);

    cout << ob.getVal() << "\n";
    cout << ob1.getVal() << "\n";

    ob.setVal(45);
    cout << ob.getVal() << "\n";

    ob1.setVal(21);
    cout << ob1.getVal() << "\n";

    ob.printAddress();
    ob1.printAddress();

    ob.reset();
    ob1.reset();

}
