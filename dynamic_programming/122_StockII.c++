#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;

        int n = prices.size(), ans = 0, bought = 0;
        int i = 0;

        while(i < n - 1){
            if(prices[i] < prices[i + 1]){
                bought = prices[i++];
                cout << "bought " << bought << '\n';
                while(i < n - 1 && prices[i] < prices[i + 1]){
                    i++;
                }
                cout << "sell " << prices[i] << '\n';
                ans += (prices[i] - bought);
            }
            i++;
        }
        return ans;
    }
};

int main () {
    Solution S;
    vector<int> prices = {7,1,5,3,6,4};
    // vector<int> prices = {1,2,3,4,5};
    // vector<int> prices = {7,6,4,3,1};
    // vector<int> prices = {2,1};
    int ans = S.maxProfit(prices);
    cout << ans << '\n';
    return 0;
}