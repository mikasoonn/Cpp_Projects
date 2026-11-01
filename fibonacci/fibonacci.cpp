#include <iostream>
using std::cout;
template <int N>
int fibonacci (){
    
   
    return fibonacci<N-1>() + fibonacci<N-2>();
    
}
template <>
int fibonacci <1>(){
    return 1;
}

template <>
int fibonacci <0>(){
    return 1;
}

int main(){
    cout << fibonacci<5>() << "\n";
}