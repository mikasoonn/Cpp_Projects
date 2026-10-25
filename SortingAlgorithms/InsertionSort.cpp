#include <iostream>
using std::cout;
template <typename Tp>
void insertionSort(Tp* arr, int n){
    for(int i = 1; i < n; i++){
        Tp key = arr[i];
        int j = i - 1;
       while(j >= 0 && arr[j] > key){
        arr[j+1] = arr[j];
        j--;
       }
       arr[j+1] = key;
    }
    
    
}

int main (){
    int arr[6] = {8,4,6,1,3,2};
    insertionSort(arr,6);
    for(int i = 0; i < 6; i++){
        cout << arr[i];
    }
    cout << "\n";
    double arr1[6] = {2.4, 4.1, 0.5, 5.1, 3.4, 0.2};
    insertionSort(arr1,6);
    for(int i = 0; i < 6; i++){
        cout << arr1[i] << " ";
    }
    cout << "\n";

}