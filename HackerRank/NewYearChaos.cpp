// void minimumBribes(vector<int> q) {
//     int n = q.size();
//     int bribeSummary = 0;

//     for (int i = 0; i < n; i++) {
//         if (q[i] - (i + 1) > 2) {
//             cout << "Too chaotic\n";
//             return;
//         }

//         for (int j = max(0, q[i] - 2); j < i; j++) {
//             if (q[j] > q[i]) {
//                 bribeSummary++;
//             }
//         }
//     }

//     cout << bribeSummary << "\n";
// }