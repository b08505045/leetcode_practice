#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;

        vector<int> arr(n + 1, 0);
        arr[0] = arr[1] = 1;
        arr[2] = 2;

        for(int i = 3; i <= n; i++){
            for(int j = 1; j <= i; j++){
                arr[i] += arr[j - 1] * arr[i - j];
            }
        }
        return arr[n];
    }
    float catalan(float n){
        if(n == 1) return 1;
        if(n == 2) return 2;
        float ans = 2;
        for(int i = 3; i <= n; i++){
            ans *= float((2 * i - 1) * 2) / float(i + 1);
            cout << "ans = " << ans << '\n';
        }
        return ans;
    }
};

int main () {
    Solution S;
    float n = 4;
    float ans = S.numTrees(n);
    // cout << ans << "\n";
    ans = S.catalan(n);
    cout << ans << "\n";
    return 0;
}