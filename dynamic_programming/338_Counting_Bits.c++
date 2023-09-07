#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0, ans[1] = 1;
        for(float i = 1; i <= n; i++){
            float log_i = log2(i);
            float fr_log_i = floor(log_i);
            cout << "log_i = " << log_i << ", fr_log_i = " << fr_log_i << '\n';
            ans[i] = (fr_log_i == log_i) ? 1 : 1 + ans[i - pow(2, fr_log_i)];
        }
        return ans;
    }
};

int main () {
    Solution S;
    int n = 16;
    vector<int> ans = S.countBits(n);
    for(auto &v : ans){
        cout << v << ',';
    }
    cout << '\n';
    return 0;
}