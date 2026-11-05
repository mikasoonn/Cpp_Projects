// int hourglassSum(vector<vector<int>> arr) {
//     int summaryArr[16];
//     int startIndex = 0;
//     for(int i = 0; i < 4; i++){
//         for(int j = 1; j < 5; j++){
//             int hourglassSum = 0;
//             hourglassSum = arr[i][j] + arr[i][j-1] + arr[i][j+1] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j-1];
//             summaryArr[startIndex++] = hourglassSum;
//             }
//     }
//     int maxValue = summaryArr[0];
//     for(int i = 0; i < 16; i++){
//         if(summaryArr[i] > maxValue){
//             maxValue = summaryArr[i];
//         }
//     }
//     return maxValue;
// }