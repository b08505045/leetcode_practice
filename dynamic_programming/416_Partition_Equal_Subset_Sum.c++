#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0, subsum = 0;
        bool ans = false;
        for(auto &v : nums){
            sum += v;
        }
        cout << sum << '\n';
        return ans;
    }
};

int main () {
    Solution S;
    vector<int> nums = {1,5,11,5};
    bool ans = S.canPartition(nums);
    cout << ans << '\n';
    return 0;
}