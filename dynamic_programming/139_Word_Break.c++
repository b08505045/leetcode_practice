// similar : 81. Search in Rotated Sorted Array II, 140. Word Break II, 2707. Extra Characters in a String
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return false;
        int n = s.length(), m = wordDict.size();
        vector<bool> ans(n + 1, false);
        ans[0] = 1;
        string temp;

        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < i; j++){
                bool found = false;
                if(ans[j]){
                    temp = s.substr(j, i - j);
                    for(int k = 0; k < m; k++){
                        if(temp == wordDict[k]){
                            ans[i] = true;
                            break;
                        }
                    }
                }
                if(found) break;
            }
        }
        for(int i = 0; i < n + 1; i++){
            cout << ans[i] << ',';
        }
        cout << '\n';
        return ans[n];
    }
};

int main () {
    // string str = "applepenapple";
    // vector<string> wordDict = {"apple","pen"};
    // string str = "leetcode";
    // vector<string> wordDict = {"leet","code"};
    string str = "catsandog";
    vector<string> wordDict = {"cats","dog","sand","and","cat"};
    Solution S;
    bool ans = S.wordBreak(str, wordDict);
    cout << ans << '\n';
    return 0;
}