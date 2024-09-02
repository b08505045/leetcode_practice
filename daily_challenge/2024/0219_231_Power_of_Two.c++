#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1 || n == 0) return true;
        if(n == 0) return false;
        while(n > 1){
            if(n % 2 != 0) return false;
            else n /= 2;
        }
        return true;
    }
};

int main () {
    Solution S;
    int n;
    cin >> n;
    cout << S.isPowerOfTwo(n);
    return 0;
}