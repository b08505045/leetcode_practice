#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return {};

        int n = nums.size();
        int prefix_sum = 1, postfix_sum = 1;
        vector<int> prefix;
        vector<int> postfix(n);
        vector<int> res;

        for(int i = 0; i < n; i++) {
            prefix.push_back(prefix_sum);
            prefix_sum *= nums[i];
        }

        for(int i = n - 1; i >= 0; i--) {
            postfix[i] = postfix_sum;
            postfix_sum *= nums[i];
        }

        for(int i = 0; i < n; i++) {
            cout << prefix[i] << ", " << postfix[i] << '\n';
        }

        for(int i = 0; i < n; i++) {
            res.push_back(prefix[i] * postfix[i]);
        }

        return res;
    }
};

int main () {
    Solution S;
    vector<int> nums = {1,2,3,4};
    vector<int> res =  S.productExceptSelf(nums);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << '\n';
    }
    return 0;
}