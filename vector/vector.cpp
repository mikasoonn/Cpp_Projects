#include <iostream>
#include <vector>
using std::vector;
using std::cout;
template <typename vectorValue>

class myVector{
    private:

    int capacity = 0;
    int size = 0;
    vectorValue *data = nullptr;

    
    public:

    myVector(){
        capacity = 0;
        size = 0;
        data = nullptr;
        cout << "Defalt constructor was called"<<"\n";
    }
    myVector(vectorValue *datas, int size) {
        cout << "Data constructor was called"<< "\n";
        this->capacity = size;
        // data = new vectorValue[capacity];
        data = static_cast<vectorValue*>(::operator new(capacity * sizeof(vectorValue)));
        if(data == nullptr){
            exit(1);
        }

        for(int i = 0; i < this->capacity; i++){
            new (&data[i]) vectorValue(datas[i]);
        }
        this->size = capacity;
    } 
    //copy constructor
    myVector(const myVector& other) {
    this->size = other.size;
    this->capacity = other.capacity;

    if (capacity > 0) {
        // data = new vectorValue[capacity];
        data = static_cast<vectorValue*>(::operator new(capacity * sizeof(vectorValue)));

        for (int i = 0; i < size; i++) {
            new (&this->data[i]) vectorValue(other.data[i]);
        }
    } else {
        data = nullptr;
    }
    }
    //
    ~myVector(){
        for(int i = 0; i < size; i++){
            this->data[i].~vectorValue();
        }
        ::operator delete(data);
        data = nullptr;
        cout <<"The destcructor was called" << "\n";
    }

    //helper functions


    int getSize() const{
        return this->size;
    }

    int getCapacity()const{
        return this->capacity;
    }

    bool empty()const{
        if(size == 0){
            return true;
        }else{
            return false;
        }
    }
    void push_back(vectorValue num){
        if(size == 0 && capacity == 0){
            capacity = 1;
            // data = new vectorValue[capacity];
            data = static_cast<vectorValue*>(::operator new(1 * sizeof(vectorValue)));
            new (&data[0]) vectorValue(num);
            this->size++;

        }else if(size == capacity){
            capacity *= 2;
            vectorValue* ptr = static_cast<vectorValue*>(::operator new(capacity * sizeof(vectorValue)));
            for(int i = 0; i < size; i++){
                new (&ptr[i]) vectorValue(this->data[i]);
            }

            for(int i = 0; i < size; i++){
                this->data[i].~vectorValue();
            }
            ::operator delete(data);
            data = ptr;
            ptr = nullptr;
            new (&data[size]) vectorValue(num);
            this->size++;
        }else {
            new (&data[size]) vectorValue(num);
            this->size++;
        }
        
    }

    vectorValue pop_back(){
        if(size == 0){
            throw std::out_of_range("Vector is empty");
        }
        vectorValue val = this->data[this->size-1];
        this->data[this->size-1].~vectorValue();
        this->size--;
        return val;
    }

    void clear(){
        cout <<"The array was cleaned"<<"\n";
        for(int i = 0; i < this->size; i++){
            this->data[i].~vectorValue();
        }
        this->size = 0;
    }

    vectorValue& operator[](int index){
        if(index >= size){
            cout << "No such index" << "\n";
            exit(1);
        }
        return data[index];
    }
    bool operator ==(const myVector& otherVector){
        if(this == &otherVector){
            return true;
        }
        if(this->size == otherVector.size){
            int i = 0;
            while(i < this->size){
                if(this->data[i] != otherVector.data[i]){
                    return false;
                }
                i++;
            }
            return true;
        }else{
            return false;
        }
    }

    bool operator !=(const myVector& otherVector){
        if(this == &otherVector){
            return false;
        }
        if(this->size == otherVector.size){
            int i = 0;
            while(i < this->size){
                if(this->data[i] != otherVector.data[i]){
                    return true;
                }
                i++;
            }
            return false;
        }else{
            return true;
        }
    }

    myVector& operator+=(const myVector& other) {
        for(int i = 0; i < other.size; i++){
            this->push_back(other.data[i]);
        }
        return *this;
    }
    //////////////////////////////////////////////////////////////////////////////
    const myVector& operator=(const myVector& vector){
        if(this == &vector){
            return *this;
        }
        for(int i = 0; i < this->size; i++){
            this->data[i].~vectorValue();
        }
        ::operator delete(this->data);
        size = vector.size;
        capacity = vector.capacity;
        data = static_cast<vectorValue*>(::operator new(this->capacity * sizeof(vectorValue)));

        for(int i = 0; i < size; i++){
            new (&this->data[i]) vectorValue(vector.data[i]);
        }

        return *this;
    }

    const myVector operator+(const myVector& vector){
        int newSize = this->size + vector.size;
        vectorValue* resArr = new vectorValue[newSize];
        for(int i = 0; i < this->size; i++){
            resArr[i] = this->data[i];
        }
        int start = 0;
        for(int i = this->size; i < newSize; i++ ){
            resArr[i] = vector.data[start++];
        }
        myVector result(resArr,newSize);
        delete []resArr;
        resArr = nullptr;
       
        return result;

    }
    void print()const{
        if(empty()){
            cout <<"The array is empty\n";
            return;
        }
        cout << "Vector Elements:"<<"\n";
        for(int i = 0; i < size;i++){
            cout << data[i]<<" ";
        }
        cout <<"\n";
    }
};
int main(){
    int nums[] = {1,2,3};
    myVector ob(nums,3);
    cout << "size: " << ob.getSize() << "\n";
    cout << "capacity: " << ob.getCapacity() << "\n";
    ob.push_back(45);
    ob.push_back(86);
    cout << "size: " << ob.getSize() << "\n";
    cout << "capacity: " << ob.getCapacity() << "\n";
    ob.print();
    ob.push_back(7);
    ob.push_back(77);
    cout << "capacity: " << ob.getCapacity() << "\n";
    ob.print();
    // ob.clear();
    cout << "size: " << ob.getSize() << "\n";
    cout << "capacity: " << ob.getCapacity() << "\n";
    ob.print();
    cout << ob[2];


    myVector <int>ob1;
    cout << "size: " << ob1.getSize() << "\n";
    cout << "capacity: " << ob1.getCapacity() << "\n";
    ob1.push_back(45);
    ob1.push_back(86);
    cout << "size: " << ob1.getSize() << "\n";
    cout << "capacity: " << ob1.getCapacity() << "\n";
    ob1.print();
    ob1.push_back(7);
    ob1.push_back(77);
    cout << "capacity: " << ob1.getCapacity() << "\n";
    ob1.print();
    // ob1.clear();
    cout << ob1.empty();
    cout << "size: " << ob1.getSize() << "\n";
    cout << "capacity: " << ob1.getCapacity() << "\n";
    ob1.print();

    ob1[2] = 6;
    cout << ob1[2] << "\n";

    myVector <int>ob2;
    ob2 = ob + ob1;
    ob.print();
    ob1.print();
    ob2.print();
    cout << ob2.empty()<<"\n";
    cout << "size: " << ob2.getSize() << "\n";
    cout << "capacity: " << ob2.getCapacity() << "\n";


}