#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty()) return word2.length();
        if(word2.empty()) return word1.length();
        int m = word1.length(), n = word2.length(), temp1 = 0, temp2 = 0, same = 0;
        vector<int> arr(n);
        char word1_0 = word1[0], word2_0 = word2[0];

        // preprocess 1st row
        arr[0] = word1_0 == word2_0 ? 0 : 1;
        for(int i = 1; i < n; i++){
            // if word2 hasn't appeared the letter same as word1[0]
            arr[i] = (arr[i - 1] == i && word1_0 != word2[i]) ? i + 1 : i; 
        }
        // dp
        for(int i = 1; i < m; i++){
            temp1 = arr[0];
            // if word1 hasn't appeared the letter same as word2[0]
            arr[0] = (arr[0] == i && word1[i] != word2_0) ? i + 1 : i;
            // process ith row
            for(int j = 1; j < n; j++){
                temp2 = arr[j];
                same = word1[i] == word2[j] ? 0 : 1;
                arr[j] = min(temp1 + same, min(arr[j - 1] + 1, arr[j] + 1));
                temp1 = temp2;
            }
        }
        return arr[n - 1];
    }
};
int main () {
    Solution S;
    // string word1 = "horse", word2 = "ros";
    string word1 = "intention", word2 = "execution";
    int ans = S.minDistance(word1, word2);
    cout << ans << "\n";
    return 0;
}