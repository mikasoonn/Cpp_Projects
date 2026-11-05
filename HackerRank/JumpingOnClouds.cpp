// int jumpingOnClouds(vector<int> c) {
//     int jumps = 0;
//     for(int i = 0; i < c.size(); i++){
//         if(i + 2 < c.size() && c[i + 2] == 0 ){
//             i++;
//             jumps++;
//         }else {
//             jumps++;
//         }
//     }
//     //As the last jump (out of array) also counts
//     return jumps-1;
// }