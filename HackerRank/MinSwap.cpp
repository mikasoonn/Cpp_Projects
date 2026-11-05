// int minimumSwaps(vector<int> arr) {
//     int minSwap = 0;
//     for(int i = 0; i < arr.size();){
//         if(arr[i] != i+1){
//             int temp = arr[i];
//             arr[i] = arr[arr[i]-1];
//             arr[temp-1] = temp;
//             minSwap++;
//         }else{
//             i++;
//         }
//     }
//     return minSwap;
// }