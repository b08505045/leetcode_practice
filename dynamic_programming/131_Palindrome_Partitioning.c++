#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.size() == 1){
            vector<vector<string>> ans = {{"a"}};
            return ans;
        }

        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        // initialize dp[][]
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        // derive dp[][]
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                dp[i][j] = (s[i] == s[j] && (i == j - 1 || dp[i + 1][j - 1] == 1)) ? 1 : 0;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << dp[i][j] << ',';
            }
            cout << '\n';
        }

        vector<string> currList;
        vector<vector<string>> ans;
        dfs(s, 0, n, dp, currList, ans);
        return ans;
    }

    void dfs(string s, int start, int length, vector<vector<int>> dp, vector<string> currList, vector<vector<string>> ans){
        if(start >= length - 1){
            ans.push_back(currList);
        }
        for(int i = start + 1; i < length; i++){
            if(dp[start][i] == 1){
                start = i;
                currList.push_back(s.substr(start, i));
                dfs(s, start, length, dp, currList, ans);
            }
        }
        currList.pop_back();
        return;
    }
};

int main () {
    string str = "aab";
    Solution S;
    vector<vector<string>> ans = S.partition(str);
    cout << ans.empty();

    for (auto &v1 : ans) {
        for(auto &v2 : v1){
            cout << v2 << ',';
        }
        cout << "\n";
    }
    return 0;
}   