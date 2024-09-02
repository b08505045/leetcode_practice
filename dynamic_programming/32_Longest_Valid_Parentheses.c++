#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    // TLE
    int longestValidParentheses(const std::string& str) {
        if(str.empty()) return 0;
        int n = str.length(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 1; i < n; i++){
            if(str[i] == ')' && str[i - 1] == '('){
                dp[i - 1][i] = 1;
                ans = 2;
            }
        }
        for(int i = n - 3; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(dp[i + 1][j - 1] == 1 && (str[i] == '(' && str[j] == ')')){
                    dp[i][j] = 1;
                    ans = max(ans, j - i + 1);
                }
                else{
                    for(int k = i; k < j; k++){
                        if(dp[i][k] == 1 && dp[k + 1][j] == 1){
                            dp[i][j] = 1;
                            ans = max(ans, j - i + 1);
                            break;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};

int main () {
    Solution S;
    string s1 = ")()())", s2 = "(()", s3 = "", s4 = "(())", s5 = "((()))())";
    int ans = S.longestValidParentheses(s5);
    cout << ans << '\n';
    return 0;
}   