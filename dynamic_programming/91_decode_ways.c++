// completed

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(int(s[0] - '0') == 0) return 0;

        int len = s.length();
        vector<int> arr(len,1);

        for(int i = 1; i < len; i++){
            // s[i] = 0 and can't be mapped
            if(int(s[i] - '0') == 0 && (int(s[i - 1] - '0') > 2 || int(s[i - 1] - '0') == 0)){
                return 0;
            }
            // s[i] = 0 but can be mapped
            else if(int(s[i] - '0') == 0 && int(s[i - 1] - '0') <= 2){
                arr[i] = (i - 2 >= 0)? arr[i - 2] : 1;
            }
            // s[i-1] = 0 or s[i-1][i] > 26
            else if(int(s[i - 1] - '0') == 0 || (int(s[i - 1] - '0') * 10 + int(s[i] - '0') > 26)){
                arr[i] = arr[i - 1];
            }
            // s[i-1][i] <= 26
            else{
                arr[i] = (i - 2 >= 0)? arr[i - 1] + arr[i - 2] : arr[i - 1] + 1;
            }
        }
        return arr[len - 1];
    }
};

int main () {
    string str = "2101";
    Solution S;
    int ans = S.numDecodings(str);
    cout << ans << "\n";
    return 0;
}