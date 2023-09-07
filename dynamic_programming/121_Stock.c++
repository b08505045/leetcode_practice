#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() == 1) return 0;
        int n = prices.size(), min = prices[0], ans = 0;
        for(int i = 1; i < n; i++){
            ans = std::max(ans, prices[i] - min);
            min = std::min(min, prices[i]);
        }
        return ans;
    }
};

int main () {
    Solution S;
    // vector<int> arr = {7,1,5,3,6,4};
    vector<int> arr = {7,6,4,3,1};
    int ans = S.maxProfit(arr);
    cout << ans << '\n';
    return 0;
}