// long repeatedString(string s, long n) {
//     long long size = s.size();
//     long long letCount = 0;
//     for(int i = 0; i < size; i++){
//         if(s[i]== 'a'){
//             letCount++;
//         }
//     }
//     long long sum = n/size;
//     n -= sum * size;
//     long long count = sum * letCount;
//     int j = 0;
    
//     while(n){
//         if(s[j] == 'a'){
//             count++;
//         }
//         n--;
//         j++;
//     }
//     return count;
// }