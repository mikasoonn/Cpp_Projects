
// long arrayManipulation(int n, vector<vector<int>> queries) {
//      vector<long long> arr(n+1, 0);
//      long long max = arr[0];
     
//      for(int i = 0; i < queries.size(); i++){
//         int start = queries[i][0];
//         int end = queries[i][1];
//         long long value = queries[i][2];
//         arr[start-1] += value;
//         arr[end] -= value;
//      }
//      for(int i = 1; i < n; i++){
//         arr[i] += arr[i-1];
//         if(arr[i] > max){
//                 max = arr[i];
//         }
//      }
//      return max;
    
    
// }