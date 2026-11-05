// int countingValleys(int steps, string path) {
//     int level = 0;
//     bool valley = false;
//     int count = 0;
//     for(int i = 0; i < path.size(); i++){
//         if(path[i] == 'U'){
//             level += 1;
//         }else{
//             level -= 1;
//         }
//         if(level < 0){
//             if(!valley){
//                 valley = true;
//                 count++;
//             }
//         }else if(level == 0 && count > 0){
//             valley = false;
//         }
//     }
//     return count;
// }