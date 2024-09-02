#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1, h = 0, l = 0;
        int curArea = 0, max = 0;

        while(left < right){
            l = right - left;
            if(height[left] < height[right]){
                h = height[left];
                left++;
            }
            else{
                h = height[right];
                right--;
            }
            curArea = l * h;
            if(curArea > max){
                max = curArea;
            }
        }
        return max;
    }
};

int main () {
    Solution S;
    return 0;
}