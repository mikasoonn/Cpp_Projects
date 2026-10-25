#include <iostream>
#include <cmath>
using std::cout;

template <typename Tp>

void merge (Tp *arr, int start,int mid, int end){
    int rsize = end - mid;
    int lsize = mid - start + 1;
    Tp left[lsize];
    Tp right[rsize];
    int k = 0;
    for(int i = start; i <= mid; i++){
        left[k++] = arr[i]; 
    }
    cout << "Left" <<"\n";
    for(int i = 0; i < lsize; i++){
        cout << left[i] << " ";
    }
    cout << "\n";
    k = 0;
    for(int i = mid + 1; i <= end; i++){
        right[k++] = arr[i]; 
    }
    cout << "Right" <<"\n";
    for(int i = 0; i < rsize; i++){
        cout << right[i] << " ";
    }
    cout << "\n";
    cout << "\n";

    int li = 0;
    int ri = 0;
    while(li < lsize && ri < rsize){
        if(left[li] <= right[ri]){
            arr[start++] = left[li++];
        }else{
            arr[start++] = right[ri++];
        }
    }

    while(li < lsize){
        arr[start++] = left[li++];
    }

    while(ri < rsize){
        arr[start++] = right[ri++];
    }

}

template <typename Tp>

void mergeSort (Tp* arr, int start, int end){
    if(start >= end){
        return;
    }
    int mid = std::floor((start + end)/2);
    mergeSort(arr,start,mid);
    mergeSort(arr,mid + 1, end);
    merge(arr,start,mid,end);

}

int main (){
    int arr[6] = {8,4,6,1,3,2};
    mergeSort(arr,0,5);
     for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}