#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int len = nums.size();
        int curSum = 0;
        int res = 0;
        std::unordered_map<int, int> count;
        count[0] = 1;

        for(int i = 0; i < len; i++) {
            curSum += nums[i];
            if(count.find(curSum - goal) != count.end()) {
                res += count[curSum - goal];
            }
            count[curSum]++;
        }
        
        return res;
    }
};

int main () {
    return 0;
}